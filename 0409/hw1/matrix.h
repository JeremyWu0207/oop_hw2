#ifndef MATRIX_H
#define MATRIX_H

class matrix {
public:
    int N;
    long long mat[3][3];

    matrix(int n = 2);
    
    // 依題目要求定義四個運算 method
    void add(matrix* A, matrix* B);
    void sub(matrix* A, matrix* B);
    void multiple(matrix* A, matrix* B);
    void divide(matrix* A, matrix* B);
};

#endif
