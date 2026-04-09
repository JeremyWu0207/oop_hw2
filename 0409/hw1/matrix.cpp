#include "matrix.h"
#include <iostream>

using namespace std;

matrix::matrix(int n) {
    N = n;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat[i][j] = 0;
}

void matrix::print() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << mat[i][j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

void matrix::add(matrix* A, matrix* B) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            this->mat[i][j] = A->mat[i][j] + B->mat[i][j];
}

void matrix::sub(matrix* A, matrix* B) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            this->mat[i][j] = A->mat[i][j] - B->mat[i][j];
}

void matrix::multiple(matrix* A, matrix* B) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            long long sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += A->mat[i][k] * B->mat[k][j];
            }
            this->mat[i][j] = sum;
        }
    }
}

void matrix::divide(matrix* A, matrix* B) {
    long long det = 0;
    long long adj[3][3] = {0};

    // 計算行列式與伴隨矩陣
    if (N == 2) {
        det = A->mat[0][0] * A->mat[1][1] - A->mat[0][1] * A->mat[1][0];
        adj[0][0] = A->mat[1][1];
        adj[0][1] = -A->mat[0][1];
        adj[1][0] = -A->mat[1][0];
        adj[1][1] = A->mat[0][0];
    } else if (N == 3) {
        det = A->mat[0][0] * (A->mat[1][1] * A->mat[2][2] - A->mat[1][2] * A->mat[2][1])
            - A->mat[0][1] * (A->mat[1][0] * A->mat[2][2] - A->mat[1][2] * A->mat[2][0])
            + A->mat[0][2] * (A->mat[1][0] * A->mat[2][1] - A->mat[1][1] * A->mat[2][0]);
        
        adj[0][0] = A->mat[1][1] * A->mat[2][2] - A->mat[1][2] * A->mat[2][1];
        adj[0][1] = -(A->mat[0][1] * A->mat[2][2] - A->mat[0][2] * A->mat[2][1]);
        adj[0][2] = A->mat[0][1] * A->mat[1][2] - A->mat[0][2] * A->mat[1][1];
        adj[1][0] = -(A->mat[1][0] * A->mat[2][2] - A->mat[1][2] * A->mat[2][0]);
        adj[1][1] = A->mat[0][0] * A->mat[2][2] - A->mat[0][2] * A->mat[2][0];
        adj[1][2] = -(A->mat[0][0] * A->mat[1][2] - A->mat[0][2] * A->mat[1][0]);
        adj[2][0] = A->mat[1][0] * A->mat[2][1] - A->mat[1][1] * A->mat[2][0];
        adj[2][1] = -(A->mat[0][0] * A->mat[2][1] - A->mat[0][1] * A->mat[2][0]);
        adj[2][2] = A->mat[0][0] * A->mat[1][1] - A->mat[0][1] * A->mat[1][0];
    }

    if (det == 0) {
        // 如果無解 (det = 0)，輸出全 0 矩陣
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                this->mat[i][j] = 0;
    } else {
        // C = A^-1 * B = (adj * B) / det
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                long long sum = 0;
                for (int k = 0; k < N; ++k) {
                    sum += adj[i][k] * B->mat[k][j];
                }
                this->mat[i][j] = sum / det; 
            }
        }
    }
}
