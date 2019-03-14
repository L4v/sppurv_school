/*
 * AUTOR: JOVAN IVOSEVIC RA30-2017
 * ZADATAK: VISEDIMENZIONALNE MATRICE
 */
#include <iostream>

#include "matrixFunctions.h"

using namespace std;

int main(int argc, char* argv[]) {

    if(argc != 3){
        cout << "Nije uneseno dovoljno parametara!" << endl << "1. n" << endl << "2. m" << endl;
        exit(-1);
    }
    int n = atoi(argv[1]), m = atoi(argv[2]);
    int* matrix_1d = new int[n*m];
    int ** matrix = new int*[n];
    for(int i = 0; i < n; i ++)
        matrix[i] = new int[m];

/*
    matrixFunctions::initMatrix1D(matrix_1d, n, m);
    matrixFunctions::printMatrix1D(matrix_1d, n, m);
    matrixFunctions::sortMatrix1D(matrix_1d, n, m);
    matrixFunctions::printMatrix1D(matrix_1d, n, m);
*/
    matrixFunctions::initMatrix2D(matrix, n, m);
    matrixFunctions::sortMatrix2D(matrix, n, m);
    matrixFunctions::printMatrix2D(matrix, n, m);



    // Ciscenje memorije
    for(int i = 0; i < n; i ++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] matrix_1d;
    return 0;
}