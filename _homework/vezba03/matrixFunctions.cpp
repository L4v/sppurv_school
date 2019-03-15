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
    for(int i = 0; i < n*m; i++){
        for(int j = 0; j < n*m; j++){
            int a = i/m, b = i%m, c = j/m, d = j%m;
            if(matrix[a][b] > matrix[c][d]){
                int tmp = matrix[a][b];
                matrix[a][b] = matrix[c][d];
                matrix[c][d] = tmp;
            }
        }
    }
    /*bool rl = false;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < m - i - 1;j++){
                if(!rl){
                    if(matrix[k][j] < matrix[k][j+1]){
                        int tmp = matrix[k][j];
                        matrix[k][j] = matrix[k][j+1];
                        matrix[k][j+1] = tmp;
                    }
                }else{
                    if(matrix[k][j] > matrix[k][j+1]) {
                        int tmp = matrix[k][j];
                        matrix[k][j] = matrix[k][j + 1];
                        matrix[k][j + 1] = tmp;
                    }
                }
            }
            rl = !rl;
        }
    }*/
    bool rl = false;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < m - 1; i ++) {
            /*if(i%m == 0){ rl = !rl; }

            cout << matrix[i / m][rl ? m - i%m - 1 : i%m] << " ";
            if((i+1)%m == 0 && i != 0){ cout << endl;}*/
            for(int j = 0; j < m - i - 1; j ++){
                if(rl){
                    if(matrix[k][j] > matrix[k][j+1]){
                        int tmp = matrix[k][j];
                        matrix[k][j] = matrix[k][j+1];
                        matrix[k][j+1] = tmp;
                    }
                }else{
                    if(matrix[k][j] < matrix[k][j+1]){
                        int tmp = matrix[k][j];
                        matrix[k][j] = matrix[k][j+1];
                        matrix[k][j+1] = tmp;
                    }
                }
            }
        }
        rl = !rl;
    }
}