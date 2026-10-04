# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>

<p align="center">Johanson Leeroy - 109082500017</p>

## Dasar Teori

### A. Dasar Bahasa C++

C++ merupakan bahasa pemrograman yang dapat digunakan untuk membuat berbagai jenis program. Beberapa konsep yang digunakan dalam praktikum ini adalah variabel, input-output, array, fungsi, pointer, reference, dan perulangan.

#### 1. Variabel dan Tipe Data

Variabel digunakan untuk menyimpan data dalam program. Setiap variabel memiliki tipe data tertentu, seperti 'int' untuk bilangan bulat, 'float' dan 'double' untuk bilangan desimal, serta 'char' untuk karakter.

#### 2. Input dan Output

'cin' digunakan untuk menerima input dari pengguna, sedangkan 'cout' digunakan untuk menampilkan output ke layar. Keduanya dapat digunakan dengan library 'iostream'.

#### 3. Array

Array digunakan untuk menyimpan beberapa data dengan tipe data yang sama dalam satu variabel. Array satu dimensi menggunakan satu indeks untuk mengakses setiap data, sedangkan array dua dimensi menggunakan dua indeks yang menunjukkan posisi baris dan kolom.

#### 4. Fungsi

Fungsi digunakan untuk mengelompokkan beberapa perintah tertentu agar dapat digunakan kembali. Fungsi dapat menerima nilai melalui parameter dan dapat mengembalikan suatu nilai menggunakan 'return'.

#### 5. Pointer

Pointer merupakan variabel yang digunakan untuk menyimpan alamat dari variabel lain. Pointer dapat digunakan untuk mengakses atau mengubah nilai dari variabel yang alamatnya disimpan.

#### 6. Reference

Reference merupakan cara untuk membuat nama lain dari suatu variabel. Dengan reference, sebuah fungsi dapat mengakses dan mengubah nilai dari variabel asli yang dikirim sebagai parameter.

#### 7. Call by Value, Call by Pointer, dan Call by Reference

Call by Value mengirimkan salinan nilai ke dalam fungsi sehingga perubahan di dalam fungsi tidak mengubah nilai variabel asli. Call by Pointer mengirimkan alamat variabel menggunakan pointer sehingga fungsi dapat mengubah nilai asli. Call by Reference mengirimkan reference dari variabel sehingga perubahan yang dilakukan dalam fungsi juga akan mengubah nilai variabel asli.

#### 8. Perulangan

Perulangan digunakan untuk menjalankan suatu perintah secara berulang. Dalam praktikum ini digunakan perulangan 'for' untuk mengakses elemen array, menampilkan data, melakukan perhitungan, dan menjalankan menu program secara berulang.

## Guided

### 1. Array

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main(){
    int i,j;
    float nilai_total, rata_rata;
    float nilai[MAX];
    static int nilai_tahun[MAX][MAX]=
    { 
        {0,2,2,0,0},
        {0,1,1,1,0},
        {0,3,3,3,0},
        {4,4,0,0,4},
        {5,0,0,0,5}
    };
    /*inisialisasi array dua dimensi */
    for (i=0; i<MAX; i++){
        cout<<"masukkan nilai ke-"<<i+1<<endl;
        cin>>nilai[i];
    }
    cout<<"\ndata nilai siswa :\n";
    /*menampilkan array satu dimensi */
    for (i=0; i<MAX; i++)
        cout<<"nilai k-"<<i+1<<"=" <<nilai[i]<<endl;
        cout<<"\n nilai tahunan : \n";
    /* menampilkan array dua dimensi */
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++)
            cout<<nilai_tahun[i][j];
            cout<<"\n";
        }
    return 0;
}
```

penjelasan singkat guided 1

Program tersebut digunakan untuk menginput dan menampilkan array satu dimensi berupa nilai siswa serta array dua dimensi berupa data nilai tahunan. Array satu dimensi 'nilai[MAX]' menyimpan 5 nilai yang dimasukkan oleh pengguna. Array dua dimensi 'nilai_tahun[MAX][MAX]' telah memiliki nilai awal dan ditampilkan menggunakan perulangan 'for'. Variabel 'i' digunakan untuk mengakses baris, dan 'j' digunakan untuk mengakses kolom pada array dua dimensi.

### 2. Pointer dan Memmory

```C++
#include <iostream>
using namespace std;

int main(){
    int x,y; // x dan y bertipe int
    int *px; // px merupakan variabel pointer menunjuk ke variabel int

    x = 87;
    px = &x;
    y = *px;

    cout << "alamat x= "<< &x << endl;
    cout << "Isi px=  "<< px << endl;
    cout << "Isi x= "<< x << endl;
    cout << "Nilai yang ditunjuk px= "<< *px << endl;
    cout << "alamat y= "<< y << endl;
    
    return 0;
}
```

penjelasan singkat guided 2

Program ini digunakan untuk memahami penggunaan pointer pada C++. Variabel px menyimpan alamat dari variabel x, sedangkan *px digunakan untuk mengambil nilai yang ada di alamat tersebut. Nilai x kemudian disalin ke variabel y melalui pointer px. Program juga menampilkan alamat dan nilai dari x, px, y, serta nilai yang ditunjuk oleh px.

### 3. Fungsi

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c);
/*mendeklarasikan prototype fungsi */

int main(){
    int x,y,z;
    cout<<"masukkan nilai bilangan ke-1 =";
    cin>>x;
    cout<<"masukkan nilai bilangan ke-2 =";
    cin>>y;
    cout<<"masukkan nilai bilangan ke-3 =";
    cin>>z;
    cout<<"nilai maksimumnya adalah ="
    <<maks3(x,y,z);
    return 0;
}
/*badan fungsi */
int maks3(int a, int b, int c){
/* deklarasi variabel lokal dalam fungsi */
    int temp_max = a;
    if(b>temp_max)
    temp_max = b;
    if(c>temp_max)
    temp_max = c;
    return (temp_max);
}
```

penjelasan singkat guided 3

Program ini digunakan untuk mencari nilai terbesar dari tiga bilangan yang dimasukkan oleh pengguna. Fungsi 'maks3()' menerima tiga nilai sebagai parameter dan membandingkannya untuk menentukan nilai terbesar. Variabel 'temp_max' digunakan untuk menyimpan nilai terbesar sementara selama proses perbandingan. Setelah ditemukan, nilai terbesar dikembalikan ke fungsi 'main()' dan ditampilkan.


### 4. Prosedur

```C++
#include <iostream>
using namespace std;

/*prototype fungsi */
void tulis(int x);

int main(){
    int jum;
    cout << " jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;
}

/*badan prosedur*/
void tulis(int x){
    for (int i=0; i<x; i++)
        cout<< "baris ke-" << i+1 << endl;
}
```

penjelasan singkat guided 4

Program ini digunakan untuk menampilkan beberapa baris tulisan sesuai jumlah yang dimasukkan oleh pengguna. Fungsi 'tulis()' menerima jumlah baris sebagai parameter, kemudian menggunakan perulangan 'for' untuk menampilkan tulisan dari baris pertama hingga terakhir. Jumlah baris ditentukan oleh nilai yang dimasukkan pada variabel 'jum'.


### 5. Parameter Fungsi

```C++
#include <iostream>
using namespace std;

void tukarValue(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

void tukarPointer(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void tukarReference(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 4, b = 6;

    //Tes Call by Value
    tukarValue(a,b);
    cout<< "Setelah Call by Value     -> a = "<< a<< ", b = "<< b<< "(tetap)"<< endl;

    //Tes Call by Pointer (mengirim alamat pakai &)
    tukarPointer(&a,&b);
    cout<< "Setelah Call by Pointer   -> a = "<< a<< ", b = "<< b<< "(berubah!)"<< endl;

    //Tes Call by Reference (Mengembalikan posisi semula)
    tukarReference(a,b);
    cout<< "Setelah Call by Reference -> a = "<< a<< ", b = "<< b<< "(Berubah lagi!)"<< endl;
}
```

penjelasan singkat guided 5

Program ini membandingkan tiga cara mengirim nilai ke fungsi, yaitu Call by Value, Call by Pointer, dan Call by Reference. Pada 'tukarValue()', perubahan hanya terjadi pada salinan nilai sehingga nilai 'a' dan 'b' tetap. Pada 'tukarPointer()' dan 'tukarReference()', nilai asli 'a' dan 'b' dapat ditukar karena fungsi mengakses data aslinya.

## Unguided

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3.

```C++
#include <iostream>
using namespace std;

int main(){
    int i,j,k;

    int matrik1 [3][3]= {
        {2,4,3},
        {4,2,1},
        {5,2,3},
    };

    int matrik2 [3][3]= {
        {2,7,4},
        {3,8,5},
        {9,6,1},
    };
    int hasil[3][3] = {};

    cout<<"Penjumlahan Matriks: "<<endl;
    for (i= 0; i<3;i++){
        for (j = 0; j<3;j++){
            cout<< matrik1[i][j] + matrik2[i][j]<<" ";
        }
        cout<< "\n";
    }

    cout<<"\n";
    cout<<"Pengurangan Matriks: "<<endl;
    for (i= 0; i<3;i++){
        for (j = 0; j<3;j++){
            cout<< matrik1[i][j] - matrik2[i][j]<<" ";
        }
        cout<< "\n";
    }

    cout<<"\n";
    cout<<"Perkalian Matriks: "<<endl;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            for (k = 0; k < 3; k++){
                hasil[i][j] += matrik1[i][k] * matrik2[k][j];
            }
        }
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << "\n";
    }
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%202/SS/1-1.png)

##### Output 2 (dengan matriks yang berbeda)

![Screenshot Output Unguided 1_2](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%202/SS/1-2.png)

penjelasan unguided 1

1. Program memanggil library 'iostream' agar dapat menggunakan 'cout' untuk menampilkan hasil ke layar.
2. Program mendeklarasikan variabel 'i', 'j', dan 'k' sebagai variabel untuk perulangan.
3. Program membuat 'matrik1' dan 'matrik2' yang masing-masing berisi matriks berukuran 3×3.
4. Program membuat array 'hasil' berukuran 3×3 dan mengisinya dengan nilai awal 0.
5. Program melakukan penjumlahan 'matrik1' dan 'matrik2' dengan menjumlahkan setiap elemen pada posisi yang sama.
6. Hasil penjumlahan kedua matriks ditampilkan menggunakan perulangan 'for'.
7. Program melakukan pengurangan 'matrik1' dan 'matrik2' dengan mengurangi setiap elemen pada posisi yang sama.
8. Hasil pengurangan kedua matriks ditampilkan menggunakan perulangan 'for'.
9. Program melakukan perkalian matriks menggunakan tiga perulangan 'for' dengan variabel 'i', 'j', dan 'k'.
10. Hasil perkalian disimpan ke dalam array 'hasil', kemudian ditampilkan ke layar.
11. Setelah seluruh operasi matriks selesai, program berakhir.


### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.

```C++
#include <iostream>
using namespace std;

void tukarValue(int x, int y, int z){
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

void tukarPointer(int *x, int *y, int *z){
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z){
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main(){
    int a = 4, b = 6, c = 1;

    //Tes Call by Value
    tukarValue(a,b,c);
    cout<< "Setelah Call by Value     -> a = "<< a<< ", b = "<< b<< ", c = "<<  c<<"(tetap)"<< endl;

    //Tes Call by Pointer (mengirim alamat pakai &)
    tukarPointer(&a,&b,&c);
    cout<< "Setelah Call by Pointer   -> a = "<< a<< ", b = "<< b<< ", c = "<<  c<<"(berubah!)"<< endl;

    //Tes Call by Reference (Mengembalikan posisi semula)
    tukarReference(a,b,c);
    cout<< "Setelah Call by Reference -> a = "<< a<< ", b = "<< b<< ", c = "<<  c<<"(Berubah lagi!)"<< endl;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%202/SS/2-1.png)

##### Output 2 (dengan nilai a, b, dan c yang berbeda)

![Screenshot Output Unguided 2_2](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%202/SS/2-2.png)

penjelasan unguided 2

1. Program memanggil library 'iostream' agar dapat menggunakan 'cout' untuk menampilkan hasil ke layar.
2. Program membuat tiga fungsi, yaitu 'tukarValue()', 'tukarPointer()', dan 'tukarReference()' untuk membandingkan tiga cara pengiriman nilai ke fungsi.
3. Fungsi 'tukarValue()' menerima tiga nilai dengan metode **Call by Value**, sehingga perubahan hanya terjadi pada salinan nilai.
4. Fungsi 'tukarPointer()' menerima alamat dari tiga variabel menggunakan pointer, sehingga dapat mengubah nilai asli dari variabel tersebut.
5. Fungsi 'tukarReference()' menerima tiga variabel menggunakan reference, sehingga perubahan juga dilakukan langsung pada nilai aslinya.
6. Pada fungsi 'main()', program membuat tiga variabel yaitu 'a = 4', 'b = 6', dan 'c = 1'.
7. Program menjalankan 'tukarValue(a,b,c)', tetapi nilai 'a', 'b', dan 'c' tetap karena fungsi hanya mengubah salinan nilainya.
8. Program menjalankan 'tukarPointer(&a,&b,&c)', sehingga nilai 'a', 'b', dan 'c' berubah menjadi '6', '1', dan '4'.
9. Program menjalankan 'tukarReference(a,b,c)', sehingga nilai kembali berubah menjadi '1', '4', dan '6'.
10. Hasil dari setiap metode ditampilkan ke layar untuk melihat perbedaan antara Call by Value, Call by Pointer, dan Call by Reference.


### 3. Diketahui sebuah array 1 dimensi sebagai berikut :
arrA = {48, 2, 7 , 21, 5, 20, 77, 9, 10, 1}
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari 
array tersebut! Kerjakan soal dengan ketentuan :
- Untuk mencari nilai minimum dan maksimum, harus dibuat menjadi sebuah function.
- Untuk mencari rata-rata harus dibuat menjadi sebuah procedure.
- Buat output di fungsi utama (main) untuk menampilkan nilai rata-rata yang sudah 
didapatkan melalui procedure sebelumnya. (Gunakan metode pass by reference atau 
pass by pointer)
- Buat menu sederhana untuk menjalankan setiap procedure

```C++
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
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%202/SS/3-1.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%202/SS/3-2.png)

penjelasan unguided 3

1. Program memanggil library 'iostream' agar dapat menggunakan 'cout' dan 'cin' untuk proses input dan output.
2. Program membuat fungsi 'maksimum()' untuk mencari nilai terbesar dari sebuah array.
3. Program membuat fungsi 'minimum()' untuk mencari nilai terkecil dari sebuah array.
4. Program membuat fungsi 'rataRata()' untuk menghitung nilai rata-rata array menggunakan reference pada variabel 'rata'.
5. Pada fungsi 'main()', program membuat array 'arrA' yang berisi 10 nilai.
6. Program menampilkan menu yang terdiri dari menampilkan array, mencari nilai maksimum, mencari nilai minimum, menghitung rata-rata, dan keluar dari program.
7. Program menggunakan perulangan 'for' dengan kondisi 'pilihan != 5' agar menu terus ditampilkan selama pengguna belum memilih menu keluar.
8. Jika pengguna memilih menu 1, program menampilkan seluruh isi array menggunakan perulangan 'for'.
9. Jika pengguna memilih menu 2 atau 3, program memanggil fungsi 'maksimum()' atau 'minimum()' untuk mencari nilai terbesar atau terkecil.
10. Jika pengguna memilih menu 4, program memanggil fungsi 'rataRata()' untuk menghitung dan menampilkan nilai rata-rata array.
11. Jika pengguna memilih menu 5, program menampilkan pesan bahwa program selesai dan menghentikan perulangan.
12. Jika pengguna memasukkan pilihan selain 1 sampai 5, program menampilkan pesan bahwa pilihan tidak valid.


## Kesimpulan

C++ memiliki beberapa konsep penting seperti array, array dua deimensi, fungsi, pointer, reference, dan perulangan. Dari praktikum ini, konsep tersebut dapat diterapkan untuk mengolah data dalam array dan array dua dimensi, mencari nilai maksimum, minimum, dan rata-rata, serta memahami perbedaan penggunaan call by value, call by pointer, dan call by reference. Praktikum ini membantu memahami penggunaan struktur data dasar dan fungsi dalam pembuatan program C++.
...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
