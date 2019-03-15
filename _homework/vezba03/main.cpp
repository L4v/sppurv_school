/*
 * AUTOR: JOVAN IVOSEVIC RA30-2017
 * ZADATAK: VISEDIMENZIONALNE MATRICE
 */
#include <iostream>
#include <vector>

#include "matrixFunctions.h"

using namespace std;

int main(int argc, char* argv[]) {

    if(argc != 4){
        cout << "Nije uneseno dovoljno parametara!" << endl << "1. n" << endl << "2. m" << endl;
        exit(-1);
    }
    int n = atoi(argv[1]), m = atoi(argv[2]);
    int max = atoi(argv[3]);
    int* matrix_1d = new int[n*m];
    int ** matrix = new int*[n];
    vector<vector<int>> matrixv(n);
    for(int i = 0; i < matrixv.size(); i ++)
        matrixv[i] = vector<int>(m);
    for(int i = 0; i < n; i ++)
        matrix[i] = new int[m];

/*
    matrixFunctions::initMatrix1D(matrix_1d, n, m, max);
    matrixFunctions::printMatrix1D(matrix_1d, n, m);
    matrixFunctions::sortMatrix1D(matrix_1d, n, m);
    matrixFunctions::printMatrix1D(matrix_1d, n, m);
*/
/*
    matrixFunctions::initMatrix2D(matrix, n, m, max);
    matrixFunctions::printMatrix2D(matrix, n, m);
    matrixFunctions::sortMatrix2D(matrix, n, m);
    matrixFunctions::printMatrix2D(matrix, n, m);
*/

    matrixFunctions::initMatrixVector(matrixv, max);
    matrixFunctions::printMatrixVector(matrixv);
    matrixFunctions::sortMatrixVector(matrixv);
    matrixFunctions::printMatrixVector(matrixv);

    /*
     * Za "dinamicki" cast, ja bih koristio pow(2, 8*sizeof(tip)) <? max, pa bih tako trazio tip, ali pretpostavljam da
     * ima bolji nacin i mrzi me
     */


    // Ciscenje memorije
    for(int i = 0; i < n; i ++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] matrix_1d;
    return 0;
}