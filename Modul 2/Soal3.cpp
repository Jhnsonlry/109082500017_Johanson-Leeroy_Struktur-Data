#include <iostream>
using namespace std;

int maksimum(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int minimum(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void rataRata(int arr[], int n, double &rata) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    rata = (double) total / n;
}

int main() {
    int arrA[10] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int pilihan;
    double rata;

    for (pilihan = 0; pilihan!=5;){
        cout << "\n=== Menu Program Array ===" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "\nIsi array: ";

            for (int j = 0; j < 10; j++) {
                cout << arrA[j] << " ";
            }

            cout << endl;
        }

        else if (pilihan == 2) {
            cout << "\nNilai maksimum = "
                 << maksimum(arrA, 10) << endl;
        }

        else if (pilihan == 3) {
            cout << "\nNilai minimum = "
                 << minimum(arrA, 10) << endl;
        }

        else if (pilihan == 4) {
            rataRata(arrA, 10, rata);

            cout << "\nNilai rata-rata = "
                 << rata << endl;
        }

        else if (pilihan == 5) {
            cout << "\nProgram selesai." << endl;
            break;
        }

        else {
            cout << "\nPilihan tidak valid!" << endl;
        }

    }

    return 0;
}