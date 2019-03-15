//
// Created by hk-47 on 3/14/19.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "matrixFunctions.h"

using namespace std;


// 1D
void matrixFunctions::initMatrix1D(int *matrix, int n, int m, int max) {
    int val;
    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            val = rand() % max + 1;
            //*(matrix + i * n + j) = j;
            int index = i * n + j;
            matrix[index] = val;
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
void matrixFunctions::initMatrix2D(int **matrix, int n, int m, int max) {
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j++)
            matrix[i][j] = rand() % max + 1;
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

// Vector
void matrixFunctions::initMatrixVector(vector<vector<int>> &matrix, int max) {
    int n = matrix[0].size();
    vector<vector<int>>::iterator it;
    vector<int>::iterator it1;
    int i = 0;
    for(it = matrix.begin(); it != matrix.end(); it++){
        for(it1 = it->begin(); it1 != it->end(); it1++, i ++)
            *it1 = rand() % max + 1;
    }
}

void matrixFunctions::printMatrixVector(vector<vector<int>> &matrix) {
    vector<vector<int>>::iterator it;
    vector<int>::iterator it1;
    for(it = matrix.begin(); it != matrix.end(); it++){
        for(it1 = it->begin(); it1 != it->end(); it1++)
            cout << *it1 << " ";
        cout << endl;
    }
}

static bool comp(int x, int y) { return x < y; }
static bool comp2(int x, int y) { return x > y; }

void matrixFunctions::sortMatrixVector(vector<vector<int>> &matrix) {
    bool rl = false;
    vector<vector<int>>::iterator it;
    for(it = matrix.begin(); it != matrix.end(); it++){
        if(!rl)
            sort(it->begin(), it->end(),comp);
        else
            sort(it->begin(), it->end(),comp2);
        rl = !rl;
    }

}