# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGINA PERTAMA)</h1>

<p align="center">Johanson Leeroy - 109082500017</p>

## Dasar Teori

### A. Singly Linked List
Singly Linked List adalah salah satu struktur data yang terdiri dari beberapa node yang saling terhubung menggunakan pointer. Setiap node memiliki dua bagian, yaitu info untuk menyimpan data dan next untuk menunjuk ke node berikutnya. Node pertama ditunjuk oleh pointer First, sedangkan node terakhir memiliki pointer next bernilai Nil karena tidak terhubung ke node lain. Singly Linked List dapat digunakan untuk menambah, menghapus, dan menampilkan data dengan memanfaatkan pointer. Berbeda dengan array, data pada linked list tidak harus disimpan secara berurutan di dalam memori, sehingga ukuran list dapat disesuaikan dengan kebutuhan selama memori masih tersedia.

## Guided

### 1. Header list

```C++
#ifndef List_h
#define List_h
#define Nil nullptr

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedList
{
    address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi (string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);
#endif
```

penjelasan singkat guided 1
Header list.h berisi deklarasi struktur data dan fungsi yang digunakan untuk membuat Singly Linked List. Di dalamnya terdapat struktur mahasiswa untuk menyimpan nama, NIM, dan umur, serta struktur node yang menyimpan data mahasiswa dan pointer ke node berikutnya. Header ini juga mendeklarasikan berbagai fungsi, seperti membuat list, menambah node, menghapus node, menampilkan data, dan menghitung jumlah node.

### 2. Code Utama list

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List)
{
    if (List.first == Nil){
        return true;
    }else{
        return false;
    }
}

void createList(linkedList &List)
{
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &list, address nodeBaru)
{
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedList &list, address nodeBaru, address prev)
{
    if (prev != Nil)
    {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    }else{
        cout<< "Node sebelumnya tidak valid"<< endl;
    }
}

void insertLast(linkedList &list, address nodeBaru)
{
    if (isEmpty(list))
    {
        list.first = nodeBaru;
    }else
    {
        address nodeBantu = list.first;
        while(nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedList &list)
{
    address nodeHapus;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }else
    {
        cout<<"List Kosong" << endl;
    }
}

void delLast(linkedList &list)
{
    address nodeHapus, nodePrev;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first; 
        if(nodeHapus->next == Nil)
        {
            list.first->next = Nil;
            dealokasi(nodeHapus);
        }else
        {
            while(nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }else
    {
        cout<<"List kosong"<< endl;
    }
}

void delAfter(linkedList &list, address nodeHapus, address nodePrev)
{
    if(isEmpty(list) == true)
    {
        cout<< "List kosong"<<endl;
    }else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }else
        {
            cout<<"Node sebelumnya (prev) tidak valid"<< endl;
        }
    }
}

void printList(linkedList list)
{
    if(isEmpty(list))
    {
        cout<< "List kosong." << endl;
    }else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}


int nbList(linkedList list)
{
    int count = 0;
    address nodeBantu = list.first;
    while(nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedList &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;

    while(nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout<< "List sudah terhapus"<< endl;
}
```

penjelasan singkat guided 2
Kode utama list.cpp berisi implementasi dari fungsi-fungsi yang sudah dideklarasikan di header. Setiap fungsi memiliki tugas masing-masing, seperti memeriksa apakah list kosong, mengalokasikan memori untuk node baru, menambahkan dan menghapus node, serta menampilkan data mahasiswa. Kode ini mengatur hubungan antar-node menggunakan pointer sehingga data dapat dikelola secara berurutan dalam linked list.

### 3. Main list

```C++
#include "list.h"
using namespace std;

int main()
{
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
}
```

penjelasan singkat guided 3
Program main.cpp digunakan untuk menjalankan dan menguji fungsi-fungsi linked list yang sudah dibuat. Program pertama-tama membuat list kosong, kemudian mengalokasikan lima node yang berisi data mahasiswa. Setelah itu, node dimasukkan menggunakan insertFirst, insertLast, dan insertAfter, lalu isi list dan jumlah node ditampilkan. Terakhir, fungsi delFirst dipanggil untuk menghapus node pertama dari list.

## Unguided

### 1.

#### Header singlylist
```C++
#ifndef SINGLYLIST_h
#define SINGLYLIST_h
#define Nil nullptr

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
};

struct List
{
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
#endif
```

#### Code Utama singlylist
```C++
#include "singlylist.h"

void createList(List &L)
{
    L.First = Nil;
}

address alokasi(infotype x)
{
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P)
{
    delete P;
    P = Nil;
}


void printInfo(List L)
{
    address P = L.First;

    while (P != Nil)
    {
        cout << P->info<< " ";
        P = P->next;
    }

    cout<<endl;
}

void insertFirst(List &L, address P)
{
    P->next = L.First;
    L.First = P;
}
```

#### Main singlylist
```C++
#include "singlylist.h"
using namespace std;

int main()
{
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    createList(L);
    P1 = alokasi(2);
    insertFirst(L,P1);
    P2 = alokasi(0);
    insertFirst(L,P2);
    P3 = alokasi(8);
    insertFirst(L,P3);
    P4 = alokasi(12);
    insertFirst(L,P4);
    P5 = alokasi(9);
    insertFirst(L,P5);
    printInfo(L);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Jhnsonlry/109082500017_Johanson-Leeroy_Struktur-Data/blob/main/Modul%204/SS/1-1.png)


penjelasan unguided 1
1. File Header ('singlylist.h') mendeklarasikan struktur 'ElmList' yang memiliki atribut 'info' bertipe 'int' dan 'next' bertipe 'address' sebagai pointer ke node berikutnya. File ini juga mendeklarasikan struktur 'List' yang memiliki atribut 'First' sebagai penunjuk ke node pertama. Selain itu, terdapat deklarasi fungsi 'createList()', 'alokasi()', 'dealokasi()', 'printInfo()', dan 'insertFirst()' untuk mengelola data dalam Singly Linked List. Penggunaan '#ifndef', '#define', dan '#endif' bertujuan mencegah header dimasukkan berulang kali.

2. File Kode Utama ('singlylist.cpp') mengimplementasikan fungsi-fungsi yang telah dideklarasikan pada file header. Fungsi 'createList()' digunakan untuk membuat list kosong, sedangkan 'alokasi()' digunakan untuk membuat node baru dan mengisi nilai 'info'. Fungsi 'dealokasi()' berfungsi membebaskan memori node, 'printInfo()' digunakan untuk menampilkan seluruh data dalam list, dan 'insertFirst()'digunakan untuk menambahkan node baru di posisi pertama list.

3. File Main ('main.cpp') berfungsi sebagai bagian utama program yang menjalankan fungsi-fungsi Singly Linked List. Program membuat list kosong melalui 'createList()', kemudian membuat lima node dengan nilai '2', '0', '8', '12', dan '9' menggunakan fungsi 'alokasi()'. Setiap node dimasukkan ke awal list menggunakan 'insertFirst()', sehingga urutan data menjadi '9 12 8 0 2'. Terakhir, fungsi 'printInfo()' dipanggil untuk menampilkan seluruh data ke layar sebelum program berakhir dengan 'return 0'.

## Kesimpulan

Di minggu kali ini saya belajar mengenai penggunaan singly linked list di bahasa pemrograman C++. Saya mempelajari cara membuat struktur node yang berisi data dan pointer ke node berikutnya, serta cara menghubungkan beberapa node menjadi sebuah list. Selain itu, saya juga belajar menggunakan beberapa fungsi seperti 'createList()', 'alokasi()', 'dealokasi()', 'insertFirst()', 'printInfo()', dan lain lain untuk mengelola data dalam linked list. Dari praktikum ini, saya menjadi lebih memahami cara kerja pointer dan bagaimana data dapat ditambahkan ke awal list sehingga urutannya berubah sesuai proses pemasukan data.
...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
