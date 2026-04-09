#include <iostream>
#include "matrix.h"

using namespace std;

int main() {
    int N;
    cout << "Input N: ";
    if (!(cin >> N)) return 0;

    matrix A(N), B(N), C(N);
    
    cout << "\nInput matrix A: ";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A.mat[i][j];
        }
    }
    
    cout << "\nInput matrix B: ";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> B.mat[i][j];
        }
    }

    while (true) {
        // 注意：這裡刻意保留了助教的錯字以符合範例輸出格式
        cout << "\n1-Addition\n2-Subtraction\n3-Mutiplicaion\n4-Divition\n5-Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            C.add(&A, &B);
            C.print();
        } else if (choice == 2) {
            C.sub(&A, &B);
            C.print();
        } else if (choice == 3) {
            C.multiple(&A, &B);
            C.print();
        } else if (choice == 4) {
            C.divide(&A, &B);
            C.print();
        } else if (choice == 5) {
            break;
        }
    }

    return 0;
}
