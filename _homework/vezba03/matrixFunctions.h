//
// Created by hk-47 on 3/14/19.
//

#ifndef VEZBA03_MATRIXFUNCTIONS_H
#define VEZBA03_MATRIXFUNCTIONS_H


class matrixFunctions {
public:
    // 1D
    static void initMatrix1D(int* matrix, int n, int m);
    static void printMatrix1D(int *matrix, int n, int m);
    static void sortMatrix1D(int* matrix, int n, int m);

    // 2D
    static void initMatrix2D(int** matrix, int n, int m);
    static void printMatrix2D(int** matrix, int n, int m);
    static void sortMatrix2D(int** matrix, int n, int m);

};


#endif //VEZBA03_MATRIXFUNCTIONS_H
