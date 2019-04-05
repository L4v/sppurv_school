#include "MorphologicalOperations.h"
#include <iostream>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "EasyBitmap\BitmapRawConverter.h"


using namespace std;

MorphologicalOperations::MorphologicalOperations(int height, int width, StructuralElement se, int seSize)
{
	m_height = height;
	m_width = width;

	//force m_seSize to be odd: if seSize is even set m_seSize to (seSize+1)
	m_seSize = ((seSize % 2) == 0) ? seSize + 1 : seSize;

	m_inputImage = new  unsigned char[m_width * m_height];
	m_outputImage = new  unsigned char[m_width * m_height];

	// fill input image buffer
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_inputImage[i * m_width + j] = rand()%2;
		}
	}

	m_structuralElement = new  unsigned char[m_seSize * m_seSize];

	// fill se buffer
	switch (se)
	{
	case SQUARE:
	{
		for (int i = 0; i < m_seSize; i++)
		{
			for (int j = 0; j < m_seSize; j++)
			{
				m_structuralElement[i * m_seSize + j] = 1;
			}
		}
		m_seCount = m_seSize*m_seSize;
		break;
	}

	case CIRCLE:
	{
		int r = m_seSize / 2;
		m_seCount = 0;
		for (int i = -r; i <= r; i++)
		{
			for (int j = -r; j <= r; j++)
			{
				if (i*i + j*j <= r*r)
				{
					m_structuralElement[(i+r) * m_seSize + (j+r)] = 1;
					m_seCount++;
				}
				else
					m_structuralElement[(i + r) * m_seSize + (j + r)] = 0;
			}
		}
		break;
	}

	case H_LINE:
	{
		for (int i = 0; i < m_seSize; i++)
		{
			for (int j = 0; j < m_seSize; j++)
			{
				if(i == (m_seSize / 2))
					m_structuralElement[i * m_seSize + j] = 1;
				else
					m_structuralElement[i * m_seSize + j] = 0;
			}
		}
		m_seCount = m_seSize;
		break;
	}
	case V_LINE:
	{
		for (int i = 0; i < m_seSize; i++)
		{
			for (int j = 0; j < m_seSize; j++)
			{
				if (j == (m_seSize / 2 ))
					m_structuralElement[i * m_seSize + j] = 1;
				else
					m_structuralElement[i * m_seSize + j] = 0;
			}
		}
		m_seCount = m_seSize;
		break;
	}

	default:
		break;
	}
}


void MorphologicalOperations::loadInputImage(const char* fileName)
{
	BitmapRawConverter inputImageBitmap((char*)fileName);
	delete[] m_inputImage;
	delete[] m_outputImage;
	m_height = inputImageBitmap.getHeight();
	m_width = inputImageBitmap.getWidth();
	const int* inImgBuffer = inputImageBitmap.getBuffer();
	
	m_inputImage = new unsigned char[m_width*m_height];
	m_outputImage = new unsigned char[m_width*m_height];


	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_inputImage[i * m_width + j] = (inImgBuffer[i * m_width + j] > 0) ? 1 : 0;
			m_outputImage[i * m_width + j] = 0;
		}
	}
}

void MorphologicalOperations::saveOutputImage(const char* fileName)
{
	BitmapRawConverter outputImageBitmap(m_width, m_height);
	int* inImgBuffer = outputImageBitmap.getBuffer();

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			inImgBuffer[i * m_width + j] = m_outputImage[i * m_width + j]*255;
		}
	}

	outputImageBitmap.pixelsToBitmap((char*)fileName);
}


int MorphologicalOperations::getNumberOfOnes(int row, int col)
{
	int sum = 0;
	
	int lowerI, upperI;
	int lowerJ, upperJ;
	int N = m_seSize / 2;

	// matrix limits
	lowerI = (row > N) ? -N : -row;
	upperI = (row < m_height - N) ? N : m_height - row - 1;
	lowerJ = (col > N) ? -N : -col;
	upperJ = (col < m_width - N) ? N : m_width - col - 1;

	for (int i = lowerI; i <= upperI; i++) 
	{
		for (int j = lowerJ; j <= upperJ; j++) 
		{
				sum += m_inputImage[(i + row) * m_width + (j + col)] * m_structuralElement[(i + N) * m_seSize + (j + N)];
		}
	}

	return sum;
}


void MorphologicalOperations::doClosingSerial()
{
	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			int ones = getNumberOfOnes(row, col);
			if (ones > 0)
				m_outputImage[row * m_width + col] = 1;
			else
				m_outputImage[row * m_width + col] = 0;
		}
	}
 
	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			m_inputImage[row * m_width + col] = m_outputImage[row * m_width + col];
		}
	}

	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			int ones = getNumberOfOnes(row, col);
			if (ones < m_seCount)
				m_outputImage[row * m_width + col] = 0;
			else
				m_outputImage[row * m_width + col] = 1;
		}
	}
}

void MorphologicalOperations::fun1(int begin1, int end1, int begin2, int end2){
	for (int row = begin2; row < end2; row++)
	{
		for (int col = begin1; col < end1; col++)
		{
			int ones = getNumberOfOnes(row, col);
			if (ones > 0)
				m_outputImage[row * m_width + col] = 1;
			else
				m_outputImage[row * m_width + col] = 0;
		}
	}
}

void MorphologicalOperations::fun2(int begin1, int end1, int begin2, int end2) {
	for (int row = begin2; row < end2; row++)
	{
		for (int col = begin1; col < end1; col++)
		{
			m_inputImage[row * m_width + col] = m_outputImage[row * m_width + col];
		}
	}
}

void MorphologicalOperations::fun3(int begin1, int end1, int begin2, int end2) {
	for (int row = begin2; row < end2; row++)
	{
		for (int col = begin1; col < end1; col++)
		{
			int ones = getNumberOfOnes(row, col);
			if (ones < m_seCount)
				m_outputImage[row * m_width + col] = 0;
			else
				m_outputImage[row * m_width + col] = 1;
		}
	}
}

void MorphologicalOperations::recursive1(int begin1, int end1, int begin2, int end2) {
	int granulacija = m_width / 8;
	int increment1 = (end1 - begin1) / 2;
	int increment2 = (end2 - begin2) / 2;
	if (end1 - begin1 <= granulacija) fun1(begin1, end1, begin2, end2);
	else {
		cilk_spawn recursive1(begin1, begin1 + increment1, begin2, begin2 + increment2);
		cilk_spawn recursive1(begin1, begin1 + increment1, begin2 + increment2, end2);
		cilk_spawn recursive1(begin1 + increment1, end1, begin2, begin2 + increment2);
		recursive1(begin1 + increment1, end1, begin2 + increment2, end2);
		cilk_sync;
	}
}

void MorphologicalOperations::recursive2(int begin1, int end1, int begin2, int end2) {
	int granulacija = m_width / 8;
	int increment1 = (end1 - begin1) / 2;
	int increment2 = (end2 - begin2) / 2;
	if (end1 - begin1 <= granulacija) fun2(begin1, end1, begin2, end2);
	else {
		cilk_spawn recursive2(begin1, begin1 + increment1, begin2, begin2 + increment2);
		cilk_spawn recursive2(begin1, begin1 + increment1, begin2 + increment2, end2);
		cilk_spawn recursive2(begin1 + increment1, end1, begin2, begin2 + increment2);
		recursive2(begin1 + increment1, end1, begin2 + increment2, end2);
		cilk_sync;
	}
}

void MorphologicalOperations::recursive3(int begin1, int end1, int begin2, int end2) {
	int granulacija = m_width / 8;
	int increment1 = (end1 - begin1) / 2;
	int increment2 = (end2 - begin2) / 2;
	if (end1 - begin1 <= granulacija) fun3(begin1, end1, begin2, end2);
	else {
		cilk_spawn recursive3(begin1, begin1 + increment1, begin2, begin2 + increment2);
		cilk_spawn recursive3(begin1, begin1 + increment1, begin2 + increment2, end2);
		cilk_spawn recursive3(begin1 + increment1, end1, begin2, begin2 + increment2);
		recursive3(begin1 + increment1, end1, begin2 + increment2, end2);
		cilk_sync;
	}
}

void MorphologicalOperations::doClosingParallel()
{
	recursive1(0, m_width, 0, m_height);
	recursive2(0, m_width, 0, m_height);
	recursive3(0, m_width, 0, m_height);
}


MorphologicalOperations::~MorphologicalOperations()
{
	delete[] m_inputImage;
	delete[] m_outputImage;
	delete[] m_structuralElement;
}
