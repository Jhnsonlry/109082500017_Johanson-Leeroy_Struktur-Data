# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>

<p align="center">Johanson Leeroy - 109082500017</p>

## Dasar Teori

### A. Dasar Bahasa C++
C++ merupakan bahasa pemrograman yang dapat digunakan untuk mengolah data dan membuat berbagai jenis program. Beberapa konsep yang digunakan dalam praktikum ini adalah variabel, struktur data, fungsi, array, pointer, reference, dan input-output.

#### 1. Variabel dan Tipe Data
Variabel digunakan untuk menyimpan data dalam program. Tipe data yang digunakan antara lain int untuk bilangan bulat, double untuk bilangan desimal, dan string untuk teks.
#### 2. Struktur Data struct
struct digunakan untuk mengelompokkan beberapa variabel dengan tipe data yang berbeda ke dalam satu struktur. Contohnya, struktur buku dapat menyimpan judul, jumlah halaman, dan nama penulis.
#### 3. Array
Array digunakan untuk menyimpan beberapa data dengan tipe data yang sama dalam satu variabel. Array satu dimensi menggunakan satu indeks, sedangkan array dua dimensi menggunakan indeks baris dan kolom untuk mengakses data.
#### 4. Fungsi
Fungsi digunakan untuk mengelompokkan perintah tertentu agar dapat digunakan kembali. Fungsi dapat menerima parameter, mengolah data, dan mengembalikan nilai menggunakan return.
#### 5. Pointer
Pointer merupakan variabel yang menyimpan alamat memori dari variabel lain. Operator & digunakan untuk mendapatkan alamat variabel, sedangkan operator * digunakan untuk mengakses nilai melalui pointer.
#### 6. Reference
Reference merupakan nama lain dari variabel yang sudah ada. Reference ditandai dengan simbol & pada deklarasi parameter fungsi dan memungkinkan fungsi mengakses serta mengubah nilai variabel asli.
#### 7. Pertukaran Data
Pertukaran data dilakukan dengan menukar nilai antara dua variabel atau elemen array. Variabel sementara seperti temp digunakan untuk menyimpan salah satu nilai agar tidak hilang selama proses pertukaran.
#### 8. Perulangan
Perulangan digunakan untuk menjalankan perintah secara berulang. Perulangan for dapat digunakan untuk mengakses elemen array, menampilkan data, dan memproses setiap baris serta kolom pada array dua dimensi.

### B. Header dan Pemisahan File Program
File header dengan ekstensi .h digunakan untuk mendeklarasikan struktur data dan fungsi yang dapat digunakan oleh file lain. Implementasi fungsi dapat ditulis pada file .cpp, sedangkan fungsi main() digunakan sebagai titik awal eksekusi program. Pemisahan file membantu membuat program lebih terstruktur dan mudah dikelola.

## Guided

### 1. Header Buku

```C++
#ifndef BUKU_H
#define BUKU_H
#include<iostream>

using namespace std;

struct buku 
{
    string judul;
    int halaman;
    string penulis;
};

void editIsi(string judul, int halaman, string penulis, buku &buku);
void TampilkanIsiBuku(buku buku);
bool CheckPenulis(buku buku);

#endif
```

penjelasan singkat guided 1
Program tersebut digunakan untuk mendefinisikan struktur data buku yang menyimpan informasi berupa judul, jumlah halaman, dan penulis buku. Struktur buku memiliki tiga atribut, yaitu judul dan penulis bertipe string, serta halaman bertipe int. Program juga mendeklarasikan tiga fungsi, yaitu editIsi() untuk mengubah isi data buku, TampilkanIsiBuku() untuk menampilkan data buku, dan CheckPenulis() untuk memeriksa apakah nama penulis kosong.


### 2. Code Utama Buku

```C++
#include "buku.h"

void editIsi(string judul, int halaman, string penulis, buku &buku)
{
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void TampilkanIsiBuku(buku buku)
{
    cout<< "Judul Buku : "<< buku.judul<< endl;
    cout<< "Halaman Buku : "<< buku.halaman<< endl;
    cout<< "Penulis Buku : "<< buku.penulis<< endl;
}

bool CheckPenulis(buku buku)
{
    return buku.penulis == "";
}
```

penjelasan singkat guided 2
Program tersebut digunakan untuk mengimplementasikan tiga fungsi yang telah dideklarasikan pada header buku. Fungsi editIsi() digunakan untuk mengisi atau mengubah data judul, jumlah halaman, dan penulis melalui parameter referensi buku &buku. Fungsi TampilkanIsiBuku() digunakan untuk menampilkan informasi buku, sedangkan fungsi CheckPenulis() mengembalikan nilai true jika nama penulis kosong dan false jika nama penulis terisi.

### 3. Main Buku

```C++
#include<iostream>
#include "buku.h"
using namespace std;

int main(){
    buku novel;
    string judul, penulis;
    int halaman;

    cout<<"Masukan Judul Buku : ";
    cin >> judul;
    cout<<"Masukan Halaman Buku : ";
    cin >> halaman;
    cout<<"Masukan Penulis Buku : ";
    cin >> penulis;

    editIsi(judul, halaman, penulis, novel);
    TampilkanIsiBuku(novel);

    cout<< CheckPenulis(novel);

    return 0;
}
```

penjelasan singkat guided 3
Program tersebut digunakan untuk menginput, menyimpan, dan menampilkan data buku menggunakan struktur buku. Variabel novel digunakan untuk menyimpan data buku, sedangkan variabel judul, halaman, dan penulis digunakan untuk menerima input dari pengguna. Fungsi editIsi() digunakan untuk memasukkan data ke dalam variabel novel, kemudian fungsi TampilkanIsiBuku() menampilkan data tersebut. Terakhir, fungsi CheckPenulis() memeriksa apakah nama penulis kosong dan menampilkan hasilnya berupa nilai 1 jika kosong atau 0 jika terisi.

## Unguided

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah arraydengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%203/SS/1-1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%203/SS/1-2.png)

penjelasan unguided 1
1. Program memanggil library iostream agar dapat menggunakan cout untuk menampilkan informasi dan hasil ke layar.
2. Program mendefinisikan konstanta MAX dengan nilai 10 sebagai ukuran maksimum array mahasiswa.
3. Program membuat struktur dataMHS yang menyimpan data mahasiswa berupa nama, NIM, nilai uts, uas, tugas, dan NilaiAkhir.
4. Program membuat fungsi NilaiAkhir() yang menerima parameter referensi Mahasiswa bertipe dataMHS untuk menghitung nilai akhir mahasiswa.
5. Fungsi NilaiAkhir() menghitung nilai akhir dengan bobot 30% untuk UTS, 40% untuk UAS, dan 30% untuk tugas, kemudian menyimpan hasilnya ke dalam atribut NilaiAkhir.
6. Program mendeklarasikan array Mahasiswa[MAX] untuk menyimpan data maksimal 10 mahasiswa.
7. Program meminta pengguna memasukkan nama dan NIM mahasiswa, kemudian menyimpannya ke dalam elemen pertama array, yaitu Mahasiswa[0].
8. Program meminta pengguna memasukkan nilai UTS, UAS, dan tugas mahasiswa, kemudian menyimpan setiap nilai ke dalam atribut yang sesuai.
9. Program memanggil fungsi NilaiAkhir() dengan parameter Mahasiswa[0] untuk menghitung dan menyimpan nilai akhir mahasiswa.
10. Program menampilkan nilai akhir mahasiswa menggunakan cout melalui atribut Mahasiswa[0].NilaiAkhir.
11. Setelah nilai akhir ditampilkan, program berakhir dengan mengembalikan nilai 0 melalui perintah return 0.

### 2. (isi dengan soal unguided 2)

#### Header Pelajaran
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include<iostream>

using namespace std;

struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```

#### Code Utama Pelajaran
```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel)
{
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran pel)
{
    cout<< "Nama Pelajaran: "<< pel.namaMapel<< endl;
    cout << "Kode Pelajaran: "<< pel.kodeMapel<< endl;
}
```

#### Main Pelajaran
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel,kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%203/SS/2-1.png)

##### Output 2

![Screenshot Output Unguided 2_2]()

penjelasan unguided 2
1. File Header (pelajaran.h) mendeklarasikan struktur 'pelajaran' yang memiliki atribut 'namaMapel' dan 'kodeMapel' bertipe 'string'. File ini juga mendeklarasikan fungsi 'create_pelajaran()' untuk membuat data pelajaran dan 'tampil_pelajaran()' untuk menampilkan data pelajaran. Penggunaan '#ifndef', '#define', dan '#endif' bertujuan mencegah header dimasukkan berulang kali.

2. File Kode Utama (pelajaran.cpp) mengimplementasikan fungsi yang telah dideklarasikan pada file header. Fungsi 'create_pelajaran()' digunakan untuk mengisi atribut nama dan kode pelajaran, kemudian mengembalikan data bertipe 'pelajaran'. Sementara itu, fungsi 'tampil_pelajaran()' digunakan untuk menampilkan nama dan kode pelajaran menggunakan 'cout'.

3. File Main (main.cpp) berfungsi sebagai bagian utama program yang menjalankan fungsi-fungsi yang telah dibuat. Program menginisialisasi variabel 'namapel' dengan nilai '"Struktur Data"' dan 'kodepel' dengan nilai '"STD"'. Selanjutnya, fungsi 'create_pelajaran()' dipanggil untuk membuat data pelajaran dan hasilnya disimpan ke dalam variabel 'pel'. Fungsi 'tampil_pelajaran()' kemudian dipanggil untuk menampilkan data tersebut ke layar sebelum program berakhir dengan 'return 0'.



### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
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
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%203/SS/3-1.png)

##### Output 2

![Screenshot Output Unguided 3_2]()

penjelasan unguided 3
1. Program memanggil library iostream agar dapat menggunakan cout untuk menampilkan informasi ke layar.
2. Program membuat fungsi tampilkanArray() untuk menampilkan isi array dua dimensi berukuran 3×3 menggunakan perulangan for. Variabel i digunakan untuk mengakses baris, sedangkan variabel j digunakan untuk mengakses kolom.
3. Program membuat fungsi tukarArray() yang menerima array arrA, arrB, serta parameter baris dan kolom untuk menentukan posisi elemen yang akan ditukar. Variabel temp digunakan untuk menyimpan sementara nilai elemen agar kedua nilai dapat ditukar.
4. Program membuat fungsi tukarPointer() yang menerima dua parameter pointer bertipe int*. Operator * digunakan untuk mengakses dan menukar nilai yang ditunjuk oleh kedua pointer dengan bantuan variabel sementara temp.
5. Pada fungsi main(), program membuat array dua dimensi A dan B, masing-masing berukuran 3×3, dengan nilai awal yang telah ditentukan.
6. Program mendeklarasikan variabel x dengan nilai 100 dan y dengan nilai 200. Pointer p1 diarahkan ke alamat variabel x, sedangkan pointer p2 diarahkan ke alamat variabel y.
7. Program menampilkan isi awal array A dan B menggunakan fungsi tampilkanArray() sebelum dilakukan pertukaran elemen.
8. Program memanggil fungsi tukarArray(A, B, 1, 2) untuk menukar elemen pada baris indeks 1 dan kolom indeks 2 dari kedua array. Dengan demikian, nilai 6 pada array A ditukar dengan nilai 60 pada array B.
9. Program menampilkan kembali array A dan B menggunakan fungsi tampilkanArray() untuk memperlihatkan hasil pertukaran elemen.
10. Program menampilkan nilai x dan y sebelum pertukaran pointer menggunakan *p1 dan *p2 untuk mengakses nilai yang ditunjuk oleh masing-masing pointer.
11. Program memanggil fungsi tukarPointer(p1, p2) untuk menukar nilai yang ditunjuk oleh kedua pointer. Karena pointer p1 dan p2 menunjuk ke variabel x dan y, nilai kedua variabel tersebut akan berubah menjadi x = 200 dan y = 100.
12. Program menampilkan nilai x dan y setelah pertukaran pointer selesai, kemudian mengakhiri program dengan perintah return 0.

## Kesimpulan

C++ memiliki beberapa konsep penting seperti variabel, tipe data, struct, array, fungsi, pointer, reference, dan perulangan. Dari praktikum ini, konsep tersebut dapat diterapkan untuk mengelola data buku, pelajaran, dan mahasiswa, menghitung nilai akhir, serta melakukan pertukaran elemen array dan nilai variabel menggunakan pointer. Praktikum ini juga membantu memahami penggunaan header, pemisahan file program, dan fungsi dalam membuat program C++ yang lebih terstruktur.
...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
