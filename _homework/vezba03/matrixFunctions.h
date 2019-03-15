//
// Created by hk-47 on 3/14/19.
//

#ifndef VEZBA03_MATRIXFUNCTIONS_H
#define VEZBA03_MATRIXFUNCTIONS_H

using namespace std;

class matrixFunctions {
public:
    // 1D
    static void initMatrix1D(int* matrix, int n, int m, int max);
    static void printMatrix1D(int *matrix, int n, int m);
    static void sortMatrix1D(int* matrix, int n, int m);

    // 2D
    static void initMatrix2D(int** matrix, int n, int m, int max);
    static void printMatrix2D(int** matrix, int n, int m);
    static void sortMatrix2D(int** matrix, int n, int m);

    // Vector
    static void initMatrixVector(vector<vector<int>>& matrix, int max);
    static void printMatrixVector(vector<vector<int>>&  matrix);
    static void sortMatrixVector(vector<vector<int>>& matrix);

};


#endif //VEZBA03_MATRIXFUNCTIONS_H
