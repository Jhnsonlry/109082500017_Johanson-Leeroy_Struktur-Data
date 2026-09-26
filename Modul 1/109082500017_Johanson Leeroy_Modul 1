# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Johanson Leeroy - 109082500017</p>

## Dasar Teori

### A. Dasar Bahasa C++<br/>
C++ merupakan bahasa pemrograman yang dapat digunakan untuk membuat berbagai jenis program. Beberapa konsep dasar yang digunakan dalam praktikum ini adalah variabel, input-output, operator, percabangan, fungsi, dan perulangan.
...

#### 1. Variabel dan Tipe Data
Variabel digunakan untuk menyimpan data. Beberapa tipe data dasar pada C++ adalah int untuk bilangan bulat, double untuk bilangan desimal, dan char untuk karakter.

#### 2. Input dan Output
Cin digunakan untuk menerima input dari pengguna, sedangkan cout digunakan untuk menampilkan output ke layar. Keduanya dapat digunakan dengan library iostream.

#### 3. Percabangan, Fungsi, dan Perulangan
Percabangan seperti if dan else digunakan untuk menjalankan perintah berdasarkan kondisi. Fungsi digunakan untuk mengelompokkan perintah tertentu agar dapat dipanggil kembali. Perulangan seperti for digunakan untuk menjalankan perintah secara berulang.

## Guided

### 1. ...

```C++
source code guided 1
```

penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```

penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```

penjelasan singkat guided 3

## Unguided

### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
using namespace std;

int main(){
    double X,Y;
    cin >> X>> Y;
    cout<< "X + Y = "<< X+Y<<endl;
    cout<< "X - Y = "<< X-Y<<endl;
    cout<< "X / Y = "<< X/Y<<endl;
    cout<< "X * Y = "<< X*Y<<endl;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%201/SS/1-1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%201/SS/1-2.png)

penjelasan unguided 1
1. Program memanggil library 'iostream' agar dapat menggunakan 'cin' dan 'cout'.
2. Program mendeklarasikan variabel 'X' dan 'Y' dengan tipe data 'double'.
3. User memasukkan dua buah nilai untuk 'X' dan 'Y'.
4. Program menghitung penjumlahan dari 'X' dan 'Y'.
5. Program menghitung pengurangan dari 'X' dan 'Y'.
6. Program menghitung pembagian dari 'X' dan 'Y'.
7. Program menghitung perkalian dari 'X' dan 'Y'.
8. Hasil dari setiap operasi ditampilkan ke layar secara berurutan.
9. Setelah semua operasi selesai, program berakhir.

### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
using namespace std;

void cetak_angka(int angka){
    if (angka == 1){
        cout<<"satu";
    }else if (angka == 2){
        cout<< "dua";
    }else if (angka == 3){
        cout<< "tiga";
    }else if (angka == 4){
        cout<< "empat";
    }else if (angka == 5){
        cout<< "lima";
    }else if (angka == 6){
        cout<< "enam";
    }else if (angka == 7){
        cout<< "tujuh";
    }else if (angka == 8){
        cout<< "delapan";
    }else if (angka == 9){
        cout<< "sembilan";
    }else if (angka == 0){
        cout<< " ";
    }
}

int main() {
    int angka;

    cin >> angka;

    if (angka>=0&&angka<=9) {
        cetak_angka(angka);
    }
    else if (angka == 10) {
        cout<<"sepuluh";
    }
    else if (angka == 11) {
        cout<<"sebelas";
    }
    else if (angka > 11 && angka <20) {
        angka = angka%10;
        cetak_angka(angka); cout<<" belas";
    }else if(angka >= 20 && angka<=99){
        int angka1 = angka / 10;
        int angka2 = angka % 10;
        cetak_angka(angka1); cout<< " puluh "; cetak_angka(angka2);
    }else if(angka == 100){
        cout<<"seratus";
    }else
        cout<<"error";

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%201/SS/2-1.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%201/SS/2-2.png)

penjelasan unguided 2
1. Program memanggil library 'iostream' untuk menggunakan 'cin' dan 'cout'.
2. Program membuat fungsi 'cetak_angka()' untuk mengubah angka 0 sampai 9 menjadi bentuk tulisan.
3. Program menerima input berupa sebuah bilangan melalui variabel 'angka'.
4. Jika angka berada di antara 0 sampai 9, program memanggil fungsi 'cetak_angka()'.
5. Jika angka adalah 10 atau 11, program langsung menampilkan “sepuluh” atau “sebelas”.
6. Jika angka berada di antara 12 sampai 19, program mengambil angka satuannya menggunakan operasi '% 10', kemudian menambahkan kata “belas”.
7. Jika angka berada di antara 20 sampai 99, program memisahkan angka puluhan dan satuan menggunakan '/ 10' dan '% 10', kemudian menambahkan kata “puluh”.
8. Jika angka adalah 100, program menampilkan “seratus”.
9. Jika angka tidak termasuk dalam rentang 0 sampai 100, program menampilkan “error”.
10. Setelah selesai menampilkan hasil, program berakhir.

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < (n - i) * 2; j++) {
            cout << " ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "*";
        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%201/SS/3-1.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%201/SS/3-2.png)

penjelasan unguided 3
1. Program menerima input nilai 'n' dari user.
2. Perulangan pertama digunakan untuk membuat baris dari 'n' hingga 0.
3. Program mencetak spasi di awal baris agar pola semakin menjorok ke kanan pada setiap baris.
4. Program mencetak angka dari 'i' hingga 1 di sebelah kiri tanda '*'.
5. Program mencetak tanda '*' sebagai titik tengah pola.
6. Program mencetak angka dari 1 hingga 'i' di sebelah kanan tanda '*'.
7. Setelah satu baris selesai, program berpindah ke baris berikutnya.
8. Proses diulangi dengan jumlah angka yang semakin sedikit hingga membentuk segitiga terbalik yang simetris.
9. Setelah seluruh baris selesai dicetak, program berakhir.

## Kesimpulan
C++ memiliki beberapa konsep dasar seperti input dan output, variabel, operator, percabangan, fungsi, dan perulangan. Dengan praktikum ini, konsep tersebut dapat diterapkan untuk membuat program sederhana, melakukan operasi aritmatika, mengubah angka menjadi tulisan, serta membuat pola menggunakan perulangan. 
...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
