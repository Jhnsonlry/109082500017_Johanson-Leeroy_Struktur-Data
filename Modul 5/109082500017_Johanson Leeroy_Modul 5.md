# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGINA KEDUA)</h1>

<p align="center">Johanson Leeroy - 109082500017</p>

## Dasar Teori

### A. Singly Linked List

Singly Linked List adalah salah satu struktur data yang terdiri dari beberapa node yang saling terhubung menggunakan pointer. Setiap node memiliki dua bagian, yaitu info untuk menyimpan data dan next untuk menunjuk ke node berikutnya. Node pertama ditunjuk oleh pointer First, sedangkan node terakhir memiliki pointer next bernilai Nil karena tidak terhubung ke node lain. Singly Linked List memungkinkan data ditambahkan, dihapus, ditampilkan, dicari, dan diperbarui dengan memanfaatkan pointer. Berbeda dengan array, node pada linked list tidak harus disimpan secara berurutan di dalam memori, sehingga penambahan data dapat dilakukan secara dinamis.

### B. Pencarian Data pada Linked List

Pencarian data pada Singly Linked List merupakan proses menemukan node yang memiliki nilai sesuai dengan data yang dicari. Proses ini dilakukan dengan menelusuri list mulai dari node pertama menggunakan pointer hingga data yang sesuai ditemukan atau mencapai akhir list. Salah satu fungsi yang dapat digunakan adalah findElm(), yang berfungsi mencari node berdasarkan nilai info. Jika data ditemukan, program dapat menampilkan informasi bahwa data tersebut tersedia dalam list. Sebaliknya, jika data tidak ditemukan setelah seluruh node diperiksa, program akan menampilkan pesan bahwa data tidak tersedia.

### C. Pembaruan Data pada Linked List

Pembaruan data pada Singly Linked List adalah proses mengubah informasi yang tersimpan di dalam suatu node tanpa harus menghapus dan membuat node baru. Pembaruan dilakukan dengan mencari atau menentukan node yang ingin diubah, kemudian mengganti nilai pada bagian info atau atribut data yang sesuai. Pada linked list yang menyimpan data mahasiswa, pembaruan dapat dilakukan berdasarkan posisi node, seperti node pertama dan terakhir, atau berdasarkan identitas tertentu seperti NIM. Contoh fungsi yang dapat digunakan adalah updateFirst(), updateLast(), updateAfter(), dan updateByNim(). Dengan fungsi tersebut, data dapat diperbarui sesuai kebutuhan tanpa mengubah hubungan pointer antar-node.

### D. Penelusuran Node Menggunakan Pointer

Penelusuran node merupakan proses mengunjungi setiap node secara berurutan dengan mengikuti pointer next. Proses ini diperlukan dalam pencarian dan pembaruan data, terutama ketika node yang ingin diakses tidak diketahui posisinya secara langsung. Penelusuran biasanya dimulai dari pointer First, kemudian berpindah ke node berikutnya hingga data yang dicari ditemukan atau pointer bernilai Nil. Pemahaman mengenai penelusuran node sangat penting agar proses pencarian dan pembaruan data dapat dilakukan dengan benar serta menghindari akses ke node yang tidak valid.

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

void updateFirst(linkedList &list);
void updateLast(linkedList &list);
void updateAfter(linkedList list,address &prev);
void updateByNim(linkedList &list, string nim);

address FindNodeByData(linkedList list, string data);
void FindNodeByAddress(linkedList list, address node);
void FindNodeByRange(linkedList list, int nilaiAwal, int nilaiAkhir);

#endif
```

penjelasan singkat guided 1
Header 'List.h' berisi deklarasi struktur data dan fungsi yang digunakan untuk mengelola Singly Linked List. Di dalamnya terdapat struktur 'mahasiswa' untuk menyimpan nama, NIM, dan umur, serta struktur 'node' yang menyimpan data mahasiswa dan pointer 'next' untuk menunjuk ke node berikutnya. Struktur 'linkedList' digunakan untuk menyimpan pointer 'first' sebagai penunjuk node pertama. Header ini juga mendeklarasikan berbagai fungsi untuk membuat list, menambah dan menghapus node di posisi tertentu, menampilkan data, menghitung jumlah node, memperbarui data mahasiswa, serta mencari node berdasarkan data, alamat, atau rentang nilai umur.

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

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedList &list)
{
		if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;
        list.first->isidata = newData;
    }
}

void updateLast(linkedList &list)
{
	if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        address nodeBantu = list.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->isidata = newData;
        }
}

void updateAfter(linkedList list,address &prev)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        prev->next->isidata = newData;
    }
}

void updateByNim(linkedList &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = FindNodeByData(list, nim);

        if (nodeBantu!= Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> newData.nama;
            cout << "Masukan nim baru : ";
            cin >> newData.nim;
            cout << "Masukan umur baru : ";
            cin >> newData.umur;
            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

address FindNodeByData(linkedList List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                // cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                // cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur<< endl;
                found = true;
                return nodeBantu;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodeByAddress(linkedList List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedList List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur >= nilaiAwal && umur <= nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```

penjelasan singkat guided 2
File list.cpp berisi implementasi dari fungsi-fungsi yang telah dideklarasikan pada header list.h untuk mengelola Singly Linked List. Fungsi-fungsinya meliputi pembuatan list, penambahan dan penghapusan node, penampilan data mahasiswa, serta perhitungan jumlah node. Selain itu, terdapat fungsi untuk memperbarui data mahasiswa dan mencari node berdasarkan nama, NIM, alamat, maupun rentang umur.

### 3. Main list

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main(){
	linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
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
    
    // updateFirst(List);
    
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE FIRST ---" << endl;
    // printList(List);

    // updateLast(List);
    
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    // // printList(List);

    // updateAfter(List, nodeC);
    
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER ---" << endl;
    // printList(List);

    updateByNim(List, "2211110014");
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);

    return 0;
}
```

penjelasan singkat guided 3
Program main.cpp digunakan untuk menjalankan dan menguji fungsi-fungsi Singly Linked List. Program diawali dengan membuat list kosong, mengalokasikan lima node berisi data mahasiswa, kemudian memasukkannya menggunakan fungsi insertFirst, insertLast, dan insertAfter. Selanjutnya, program menampilkan isi list dan jumlah node. Terdapat juga beberapa kode yang dikomentari, yaitu updateFirst untuk memperbarui data pada node pertama, updateLast untuk node terakhir, dan updateAfter untuk node setelah posisi tertentu. Karena kode tersebut dikomentari, fungsi-fungsi itu tidak dijalankan. Program kemudian menjalankan updateByNim untuk memperbarui data mahasiswa berdasarkan NIM tertentu dan menampilkan kembali isi list setelah diperbarui.

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
address findElm(List L, infotype x);
void sumInfo(List L);

#endif
```

#### Code Utama singlylist
```C++
#include "singlylist.h"
using namespace std;
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

address findElm(List L, infotype x)
{
    address nodeBantu = L.First;
    int posisi = 0;
    bool found = false;
    while (nodeBantu != Nil)
    {
        posisi++;
        if (nodeBantu->info == x)
        {
            cout<< x << " ditemukan dalam list";
            found = true;
        }
        nodeBantu = nodeBantu->next;
    }
    if (found == false)
    {
    cout << "Node dengan data " << x << " tidak ditemukan!" << endl;
    }
    cout << endl;
    return Nil;
}

void sumInfo(List L)
{
    address P = L.First;
    int total = 0;

    while (P != Nil)
    {
        total += P->info;
        P = P->next;
    }

    cout << "Total info dari kelima element adalah "<< total;
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

    findElm(L, 8);

    sumInfo(L);
    
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1]()

penjelasan unguided 1
1. File Header (singlylist.h) mendeklarasikan struktur ElmList yang memiliki atribut info bertipe int untuk menyimpan data dan next bertipe address sebagai pointer ke node berikutnya. File ini juga mendeklarasikan struktur List dengan atribut First sebagai penunjuk ke node pertama. Selain itu, terdapat deklarasi fungsi createList(), alokasi(), dealokasi(), printInfo(), insertFirst(), findElm(), dan sumInfo() untuk mengelola, mencari, serta menjumlahkan data dalam Singly Linked List. Penggunaan #ifndef, #define, dan #endif bertujuan mencegah header dimasukkan berulang kali.

2. File Kode Utama (singlylist.cpp) mengimplementasikan fungsi-fungsi yang telah dideklarasikan pada file header. Fungsi createList() digunakan untuk membuat list kosong, alokasi() untuk membuat node baru dan mengisi nilai info, sedangkan dealokasi() berfungsi membebaskan memori node. Fungsi printInfo() digunakan untuk menampilkan seluruh data, dan insertFirst() untuk menambahkan node di awal list. Selain itu, fungsi findElm() digunakan untuk mencari data tertentu dalam list, sedangkan sumInfo() digunakan untuk menjumlahkan seluruh nilai info pada setiap node dan menampilkan hasil penjumlahannya.

3. File Main (main.cpp) berfungsi sebagai bagian utama program yang menjalankan fungsi-fungsi Singly Linked List. Program membuat list kosong melalui createList(), kemudian membuat lima node dengan nilai 2, 0, 8, 12, dan 9 menggunakan fungsi alokasi(). Setiap node dimasukkan ke awal list menggunakan insertFirst(), sehingga urutan data menjadi 9 12 8 0 2. Selanjutnya, fungsi printInfo() dipanggil untuk menampilkan seluruh data, findElm() untuk mencari nilai 8, dan sumInfo() untuk menjumlahkan seluruh nilai dalam list. Hasil penjumlahannya adalah 31, sebelum program berakhir dengan return 0.

## Kesimpulan

Di minggu kali ini saya belajar mengenai pencarian dan pembaruan data pada Singly Linked List menggunakan bahasa pemrograman C++. Saya mempelajari cara mencari node berdasarkan data tertentu, seperti nama atau NIM, serta memperbarui informasi mahasiswa pada node yang dipilih. Selain itu, saya juga memahami penggunaan fungsi seperti findElm(), updateFirst(), updateLast(), updateAfter(), dan updateByNim() untuk membantu proses pencarian dan pembaruan data. Dari praktikum ini, saya menjadi lebih memahami cara menelusuri node menggunakan pointer serta bagaimana data dalam linked list dapat dicari dan diperbarui tanpa harus membuat list baru.
...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
