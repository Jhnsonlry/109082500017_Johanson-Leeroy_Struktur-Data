# <h1 align="center">Laporan Praktikum Modul 7 - STACK (BAGIAN PERTAMA)</h1>

<p align="center">Johanson Leeroy - 109082500017</p>

## Dasar Teori

### A. Stack
Stack adalah salah satu struktur data linear yang menggunakan prinsip LIFO (Last In, First Out), yaitu data yang terakhir dimasukkan akan menjadi data pertama yang dikeluarkan. Penambahan dan penghapusan data pada Stack dilakukan melalui satu ujung yang disebut top.

Stack memiliki beberapa operasi utama, yaitu push untuk menambahkan data, pop untuk menghapus data teratas, dan printInfo untuk menampilkan isi Stack.

Komponen-komponen dalam Stack:
1. Top : variabel yang menunjukkan posisi elemen paling atas pada Stack.
2. Info : array yang digunakan untuk menyimpan elemen-elemen data pada Stack.
3. Push : operasi untuk menambahkan elemen baru ke bagian atas Stack.
4. Pop : operasi untuk mengambil dan menghapus elemen paling atas dari Stack.
Pada implementasinya, Stack dapat menggunakan Array maupun Linked List sebagai media penyimpanan data. Dalam praktikum ini, Stack menggunakan Array dengan kapasitas maksimal 20 elemen.

## Guided 1 (Stack dengan Array)

### 1. Header stack

```C++
#ifndef STACK_TABLE
#define STACK_TABLE
#include <iostream>
using namespace std;
const int MAX = 10;

struct stackTable
{
    int data[MAX];
    int top;
};
bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);
void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

penjelasan singkat guided 1

File stack.h berisi deklarasi struktur data dan fungsi-fungsi untuk mengelola Stack menggunakan Array. Struktur stackTable memiliki array data dengan kapasitas maksimal 10 elemen dan variabel top untuk menunjukkan posisi elemen paling atas. Header ini juga mendeklarasikan fungsi untuk mengecek kondisi Stack, membuat Stack kosong, menambah data (push), menghapus data (pop), memperbarui data (update), menampilkan data (view), dan mencari data (searchData).

### 2. Code Utama stack

```C++
#include "stack.h"

bool isEmpty(stackTable s)
{
    return s.top == -1;
}
bool isFull(stackTable s)
{
    return s.top == MAX-1;
}
void createStack(stackTable &s)
{
    s.top = -1;
}
void push(stackTable &s, int angka)
{

    if (isFull(s))
    {
        cout<< "Stack penuh!"<< endl;
    }
    else
    {
        s.top++;
        s.data[s.top] = angka;
        cout<<"Data "<< angka<< " berhasil ditambahkan kedalam stack !"<< endl;
    }
}
void pop(stackTable &s)
{
    if (isEmpty(s))
    {
        cout<< "Stack kosong!"<< endl;
    }
    else
    {
        int val = s.data[s.top];
        s.top--;
        cout<<"Data "<< val << " berhasil dihapus dari stack !"<< endl;
    }
}
void update(stackTable &s, int posisi)
{
    if(isEmpty(s))
    {
        cout<< "Stack kosong!"<< endl;
    }
    if (posisi <=0)
    {
        cout<< "Posisi tidak valid"<< endl;
        return;
    }
    // inndex = top

    int idx = s.top - (posisi -1);
    if(idx < 0 || idx > s.top)
    {
        cout<<"Posisi "<< posisi<< " tidak valid!"<< endl;
        return;
    }
    
    cout<<"Update data posisi ke-"<< posisi<<endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}
void view(stackTable s)
{
    if (isEmpty(s))
    {
        cout<< "Stack Kosong!"<<endl;
    }
    else
    {
        for (int i = s.top; i>= 0; --i)
        {
            cout<< s.data[i]<< " ";
        }
    }
    cout << endl;
}
void searchData(stackTable s, int data)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for (int i = s.top; i >= 0; --i)
    {
        if (s.data[i] == data)
        {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if (!found)
    {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```

penjelasan singkat guided 2

File implementasi berisi definisi fungsi-fungsi yang telah dideklarasikan pada stack.h. Operasi penambahan dan penghapusan data dilakukan dengan mengatur indeks top pada array. Selain itu, terdapat fungsi untuk memperbarui data berdasarkan posisi, menampilkan isi Stack dari elemen teratas, serta mencari data berdasarkan nilainya.

### 3. Main stack

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    update(s, 2);
    update(s, 1);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```

penjelasan singkat guided 3

File main.cpp digunakan untuk menjalankan dan menguji operasi Stack menggunakan Array. Program diawali dengan membuat Stack kosong, kemudian memasukkan lima data menggunakan fungsi push. Selanjutnya, program menampilkan isi Stack, menghapus dua data menggunakan pop, memperbarui data menggunakan update, dan mencari data menggunakan searchData.

## Guided 2 (Stack dengan Linked List)

### 1. Header stack

```C++
#ifndef STACK
#define STACK
#define Nil NULL
#include <iostream>
using namespace std;
typedef struct node *address;

struct node
{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi (int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

penjelasan singkat guided 1

File stack.h berisi deklarasi struktur data dan fungsi-fungsi untuk mengelola Stack menggunakan Linked List. Struktur node menyimpan nilai data dan pointer next untuk menghubungkan node berikutnya, sedangkan struktur stack memiliki pointer top sebagai penunjuk node paling atas. Header ini juga mendeklarasikan fungsi untuk membuat Stack kosong, alokasi dan dealokasi node, serta operasi push, pop, update, view, dan searchData.

### 2. Code Utama stack

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack)
{
    if (listStack.top == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createStack(stack &listStack)
{
    listStack.top = Nil;
}

address alokasi(int angka)
{
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru)
{
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack)
{
    address nodeHapus;
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " << nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi)
{
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        if (posisi == 0)
        {
            cout << "Posisi tidak valid!" << endl;
        }
        else
        {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while (nodeBantu != Nil)
            {
                if (count < posisi)
                {
                    nodeBantu = nodeBantu->next;
                    count++;
                }
                else if (count == posisi)
                {
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        while (nodeBantu != Nil)
        {
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while (nodeBantu != Nil)
        {
            if (nodeBantu->dataAngka == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            }
            else
            {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if (found == false)
        {
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

penjelasan singkat guided 2

File implementasi berisi definisi fungsi-fungsi yang digunakan untuk mengelola Stack menggunakan Linked List. Penambahan data dilakukan dengan membuat node baru dan menghubungkannya ke posisi paling atas, sedangkan penghapusan dilakukan dengan melepas dan menghapus node teratas. Selain itu, terdapat fungsi untuk memperbarui data berdasarkan posisi, menampilkan isi Stack, dan mencari data menggunakan pointer untuk menelusuri node.

### 3. Main stack

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

penjelasan singkat guided 3

File main.cpp digunakan untuk menjalankan dan menguji operasi Stack menggunakan Linked List. Program diawali dengan membuat Stack kosong dan mengalokasikan lima node yang berisi data angka 1 sampai 5. Selanjutnya, seluruh node dimasukkan menggunakan push, kemudian program menampilkan isi Stack, menghapus dua data menggunakan pop, memperbarui data menggunakan update, dan mencari data menggunakan searchData.

## Unguided

### 1.

#### Header Stack
```C++
#ifndef STACK
#define STACK
#include <iostream>
using namespace std;
const int MAX = 20;

typedef int infotype;

struct Stack
{
    infotype info[MAX];
    int top;
};

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);

#endif
```

#### Code Utama Stack
```C++
#include "stack.h"

void CreateStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top == 19) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";

        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }

        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        int i = 0;
        int j = S.top;

        while (i < j) {
            infotype temp = S.info[i];
            S.info[i] = S.info[j];
            S.info[j] = temp;

            i++;
            j--;
        }
    }
}

void pushAscending(Stack &S, int x) {
    if (S.top == 19) {
        cout << "Stack penuh!" << endl;
    } else {
        int i = S.top;

        while (i >= 0 && S.info[i] > x) {
            S.info[i + 1] = S.info[i];
            i--;
        }

        S.info[i + 1] = x;
        S.top++;
    }
}



void getInputStream(Stack &S) {
    char input;
    while (true) {
        input = cin.get();

        if (input == '\n') {
            break;
        }

        if (input >= '0' && input <= '9') {
            if (S.top == 19) {
                cout << "Stack penuh!" << endl;
                break;
            }

            push(S, input - '0');
        }
    }
}
```

#### Main Stack
```C++
#include "stack.h"

int main()
{
    cout << "Hello world!" << endl;

    Stack S;

    CreateStack(S);

    push(S,3);
    push(S,4);
    push(S,8);

    pop(S);

    push(S,2);
    push(S,3);

    pop(S);

    push(S,9);

    printInfo(S);

    cout<<"balik stack"<<endl;

    balikStack(S);
    printInfo(S);

    cout << "Hello world!" << endl;
    Stack S;

    CreateStack(S);

    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);

    printInfo(S);

    cout<<"balik stack"<<endl;

    balikStack(S);
    printInfo(S);

    cout << "Hello world!" << endl;

    Stack S;

    CreateStack(S);
    getInputStream(S);
    printInfo(S);

    cout<<"balik stack"<<endl;

    balikStack(S);
    printInfo(S);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1]()

![Screenshot Output Unguided 1_2]()

![Screenshot Output Unguided 1_3]()

penjelasan unguided 1
1. File stack.h berisi deklarasi struktur data dan prosedur serta fungsi yang digunakan untuk mengelola Stack menggunakan Array. Struktur Stack memiliki atribut info berupa array dengan kapasitas maksimal 20 elemen untuk menyimpan data bertipe integer, serta top untuk menunjukkan posisi elemen paling atas Stack. File header juga mendeklarasikan prosedur dan fungsi seperti CreateStack(), push(), pop(), printInfo(), balikStack(), pushAscending(), dan getInputStream() untuk membuat Stack kosong, menambahkan dan menghapus data, menampilkan isi Stack, membalik urutan data, memasukkan data secara berurutan dari terkecil ke terbesar, serta menerima input angka dari pengguna. Penggunaan #ifndef, #define, dan #endif bertujuan untuk mencegah file header dimasukkan berulang kali.

2. File stack.cpp berisi implementasi dari prosedur dan fungsi yang telah dideklarasikan pada file header. Prosedur CreateStack() digunakan untuk membuat Stack kosong dengan mengatur nilai top menjadi -1. Fungsi push() digunakan untuk menambahkan data ke bagian atas Stack dengan memeriksa kapasitas array, sedangkan pop() digunakan untuk mengambil sekaligus menghapus data teratas. Prosedur printInfo() digunakan untuk menampilkan seluruh isi Stack mulai dari elemen teratas. Prosedur balikStack() berfungsi membalik urutan elemen dengan menukar posisi data dari kedua ujung array. Selain itu, pushAscending() digunakan untuk memasukkan data dengan urutan ascending atau dari nilai terkecil ke terbesar. Prosedur getInputStream() digunakan untuk membaca input angka dari pengguna menggunakan cin.get() dan memasukkannya ke dalam Stack hingga pengguna menekan tombol Enter. Pada proses input, karakter angka dikonversi menjadi tipe integer sebelum disimpan ke dalam array.

3. File main.cpp berfungsi sebagai bagian utama program untuk menjalankan dan menguji seluruh prosedur serta fungsi Stack. Program pertama-tama membuat Stack kosong menggunakan CreateStack(), kemudian melakukan beberapa operasi penambahan dan penghapusan data menggunakan push() dan pop(). Setelah itu, program menampilkan isi Stack menggunakan printInfo() dan membalik urutan data menggunakan balikStack(). Selanjutnya, program membuat Stack baru untuk menguji fungsi pushAscending() dengan memasukkan beberapa angka agar data tersusun secara ascending. Program kemudian menampilkan isi Stack dan menguji kembali proses pembalikan urutan data. Terakhir, program membuat Stack baru untuk menguji getInputStream(), yaitu menerima input angka dari pengguna hingga tombol Enter ditekan, menampilkan isi Stack, dan membalik urutan data. Dengan demikian, program utama ini digunakan untuk menguji operasi dasar Stack, pengurutan data, pembalikan urutan, serta penerimaan input pengguna.

## Kesimpulan

Di minggu kali ini saya belajar mengenai pengelolaan data menggunakan struktur data Stack dengan bahasa pemrograman C++. Saya mempelajari cara menambahkan data menggunakan push(), menghapus data menggunakan pop(), serta menampilkan isi Stack menggunakan printInfo(). Selain itu, saya juga memahami penggunaan prosedur balikStack() untuk membalik urutan data, pushAscending() untuk memasukkan data secara berurutan dari terkecil ke terbesar, dan getInputStream() untuk menerima input angka dari pengguna. Dari praktikum ini, saya menjadi lebih memahami prinsip kerja Stack yaitu LIFO (Last In, First Out), serta perbedaan pengelolaan data menggunakan Array dan bagaimana operasi Stack memengaruhi urutan elemen di dalamnya.
...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
