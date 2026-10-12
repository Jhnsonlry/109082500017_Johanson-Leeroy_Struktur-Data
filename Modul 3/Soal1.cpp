#include <iostream>
#define MAX 10
using namespace std;
struct dataMHS
{
    string nama, NIM;
    double uts, uas, tugas, NilaiAkhir;
};

double NilaiAkhir(dataMHS &Mahasiswa){
    Mahasiswa.NilaiAkhir = (0.3 * Mahasiswa.uts) + (0.4 * Mahasiswa.uas) + (0.3 * Mahasiswa.tugas);
    return Mahasiswa.NilaiAkhir;
}

int main(){
    dataMHS Mahasiswa[MAX];
    cout<< "Masukan Nama: ";
    cin >> Mahasiswa[0].nama;
    cout<< "Masukan NIM: ";
    cin >> Mahasiswa[0].NIM;
    cout<< "Masukan Nilai UTS: ";
    cin >> Mahasiswa[0].uts;
    cout<< "Masukan Nilai UAS: ";
    cin >> Mahasiswa[0].uas;
    cout<< "Masukan Nilai Tugas: ";
    cin >> Mahasiswa[0].tugas;
    NilaiAkhir(Mahasiswa[0]);

    cout << "Nilai Akhir: "<< Mahasiswa[0].NilaiAkhir;
    return 0;
}