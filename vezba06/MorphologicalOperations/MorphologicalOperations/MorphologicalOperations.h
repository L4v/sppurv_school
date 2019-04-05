#pragma once

typedef enum
{
	SQUARE,
	CIRCLE,
	H_LINE,
	V_LINE
} StructuralElement;

class MorphologicalOperations
{
private:
	//! image width and height
	int m_width;
	int m_height;

	//! holds input image data
	unsigned char* m_inputImage;

	//! holds output image data
	unsigned char* m_outputImage;

	//! structural element size 
	int m_seSize;

	//! number of "ones" in structural elemen
	int m_seCount;
	
	//! holds the structural element
	unsigned char* m_structuralElement;


	/**
	* @brief Calculate how many fileds with value 1 are in the scope 
	* of the structure element when structure element is placed on top 
	* of the pixel with coordinates [row][col] 
	* 
	* @param row cell row
	* @param col cell column
	*/
	int getNumberOfOnes(int row, int col);

public:
	/**
	* @brief Constuctor.
	*
	* @param height board height
	* @param width board withd
	* @param model init board model
	*/
	MorphologicalOperations(int height, int width, StructuralElement se, int seSize);

	/**
	* @brief default destructor.
	*/
	~MorphologicalOperations();

	/**
	* @brief Perform serial version of morphological closing algorithm.
	*/
	void doClosingSerial();

	/**
	* @brief Perform serial version of morphological closing algorithm.
	*/
	void doClosingParallel();

	/**
	* @brief Recursive methods for induvidual calculations
	*/
	void recursive_erosion(int, int, int, int);
	void recursive_cito(int, int, int, int);
	void recursive_dilatation(int, int, int, int);
	
	/**
	* @brief Methods for individual calculations, for loops from doClosingSerial() divided into 3 methods
	*/
	void erosion(int, int, int, int);
	void copy_input_to_output(int, int, int, int);
	void dilatation(int, int, int, int);

	/**
	* @brief Load input image from file.
	*/
	void loadInputImage(const char* fileName);

	/**
	* @brief Save output image to file.
	*/
	void saveOutputImage(const char* fileName);


};
