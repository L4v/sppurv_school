#pragma once


#include <cilk/cilk.h>

typedef enum InitModel
{
	RANDOM,
	PULSAR
};

class GameOfLife
{
private:
	//! board width and height
	unsigned int m_width;
	unsigned int m_height;

	//! holds init board state
	unsigned char* m_buffer;

	//! holds next iteration board state
	unsigned char* m_nextIter;

	/**
	* @brief Calculate how much neighbours cell has.
	* 
	* @param row cell row
	* @param col cell column
	*/
	int getNeighbourSum(unsigned int row, unsigned int col);

public:
	/**
	* @brief Constuctor.
	*
	* @param height board height
	* @param width board withd
	* @param model init board model
	*/
	GameOfLife(unsigned int height, unsigned int width, InitModel model);

	/**
	* @brief default destructor.
	*/
	~GameOfLife();

	/**
	* @brief Game of life serial version for one iteration.
	*/
	void nextIterSerial();

	/**
	* @brief Game of life parallel version for one iteration.
	*/
	void nextIterParallel();

	/**
	* @brief Print board to console.
	*/
	void printIteration();
	void nextIterPiece(int, int, int);
	void nextIterParallelRecursive(int, int);
};
