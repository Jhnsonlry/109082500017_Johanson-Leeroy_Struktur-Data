
#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int arrA[3][3], int arrB[3][3],int baris, int kolom) {
    int temp = arrA[baris][kolom];
    arrA[baris][kolom] = arrB[baris][kolom];
    arrB[baris][kolom] = temp;
}


void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };
    int x = 100;
    int y = 200;

    int *p1 = &x;
    int *p2 = &y;
    cout << "=== Array Sebelum Ditukar ===" << endl;

    cout << "\nArray A:" << endl;
    tampilkanArray(A);

    cout << "\nArray B:" << endl;
    tampilkanArray(B);

    tukarArray(A, B, 1, 2);

    cout << "\n=== Array Setelah Ditukar ===" << endl;

    cout << "\nArray A:" << endl;
    tampilkanArray(A);

    cout << "\nArray B:" << endl;
    tampilkanArray(B);

    cout << "\n=== Pertukaran Pointer ===" << endl;
    cout << "Nilai x sebelum ditukar: " << *p1 << endl;
    cout << "Nilai y sebelum ditukar: " << *p2 << endl;

    tukarPointer(p1, p2);

    cout << "\nNilai x setelah ditukar: " << *p1 << endl;
    cout << "Nilai y setelah ditukar: " << *p2 << endl;

    return 0;
}
