#include "MorphologicalOperations.h"
#include <iostream>
#include "cilktime.h"

using namespace std;

//! Input file:
char* filename = "pulp_fiction.bmp";

int main(int argc, char* argv[])
{
	unsigned long long startTicks;
	unsigned long long endTicks;

	// Create a MO object with a 5x5 square structure element
	// If "loadInputImage" is not invoked, a random image 
	// with the size od 640x640 will be generated
	MorphologicalOperations morphoOp(640, 640, SQUARE, 5);

	morphoOp.loadInputImage(filename);
	
	// serial version
	startTicks = cilk_getticks();
	
	morphoOp.doClosingSerial();
	
	endTicks = cilk_getticks();
	cout << "Serial time: \t\t\t" << endTicks - startTicks << " ticks\n";

	morphoOp.saveOutputImage("outputSerial.bmp");


	// load image for parallel version
	morphoOp.loadInputImage(filename);

	// parallel version
	startTicks = cilk_getticks();

	// TODO: IMPLEMENT PARALLEL FUNCTION
	morphoOp.doClosingParallel();

	endTicks = cilk_getticks();
	cout << "Parallel time: \t" << endTicks - startTicks << " ticks\n";

	morphoOp.saveOutputImage("outputParallel.bmp");

}
