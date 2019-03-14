//
// Created by hk-47 on 3/14/19.
//

#include <iostream>

#include "matrixFunctions.h"

using namespace std;


// 1D
void matrixFunctions::initMatrix1D(int *matrix, int n, int m) {
    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            //*(matrix + i * n + j) = j;
            int index = i * n + j;
            matrix[index] = index;
        }
    }
}

void matrixFunctions::printMatrix1D(int *matrix, int n, int m) {
    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            int index = i * n + j;
            cout << matrix[index] << " ";
        }
        cout << endl;
    }
}

void matrixFunctions::sortMatrix1D(int *matrix, int n, int m) {
    for(int i = 0; i < n*m - 1; i ++){
        for(int j = 0; j < n*m -i -1; j ++){
            if(matrix[j] < matrix[j+1]){
                int tmp = matrix[j];
                matrix[j] = matrix[j+1];
                matrix[j+1] = tmp;
            }
        }
    }
}

// 2D
void matrixFunctions::initMatrix2D(int **matrix, int n, int m) {
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j++)
            matrix[i][j] = i * n + j;
}

void matrixFunctions::printMatrix2D(int **matrix, int n, int m) {
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
        }
}

void matrixFunctions::sortMatrix2D(int **matrix, int n, int m) {
    bool t = false;
    int index;
    for(int i = 0; i < n*m - 1; i ++){
        for(int j = 0; j < n*m - i - 1; j++){
            index = t ? m - j - 1: j;
            if(matrix[i/n][i%m] < matrix[j/m][j%m]){
                int tmp = matrix[i/n][i%4];
                matrix[i/4][i%4] = matrix[j/4][j%4];
                matrix[j/4][j%4] = tmp;
            }
        }
        t = !t;
    }
}