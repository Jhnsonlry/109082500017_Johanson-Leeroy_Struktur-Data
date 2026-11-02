#include "Doublylist.h"

void CreateList(List &L)
{
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x)
{
    address P = new ElmList;

    P->info = x;
    P->next = Nil;
    P->prev = Nil;

    return P;
}

void dealokasi(address &P)
{
    if (P != Nil)
    {
        P->next = Nil;
        P->prev = Nil;

        delete P;
        P = Nil;
    }
}

void printInfo(List L)
{
    address P = L.Last;

    cout << endl;
    cout << "DATA LIST 1" << endl;
    cout << endl;

    while (P != Nil)
    {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;

        P = P->prev;
    }
}

void insertLast(List &L, address &P)
{
    infotype x;

    cout << "masukkan nomor polisi: ";
    getline(cin, x.nopol);

    address Q = L.First;

    cout << "masukkan warna kendaraan: ";
    getline(cin, x.warna);

    cout << "masukkan tahun kendaraan: ";
    cin >> x.thnBuat;
    cin.ignore(1000, '\n');

    while (Q != Nil)
    {
        if (Q->info.nopol == x.nopol)
        {
            cout << "nomor polisi sudah terdaftar"<< endl;
            cout<< endl;
            P = Nil;
            return;
        }

        Q = Q->next;
    }

    P = alokasi(x);

    if (L.First == Nil)
    {
        L.First = P;
        L.Last = P;
    }
    else
    {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }

    cout << endl;
}


void findElm(List L, infotype x)
{
    cout << "Masukkan Nomor Polisi yang dicari : ";
    getline(cin, x.nopol);

    address P = L.First;

    while (P != Nil)
    {
        if (P->info.nopol == x.nopol)
        {
            cout << endl;
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.thnBuat << endl;

            return;
        }

        P = P->next;
    }

    cout << endl;
    cout << "Nomor polisi " << x.nopol << " tidak ditemukan." << endl;
}


void deleteFirst(List &L, address P)
{
    if (L.First == Nil)
    {
        cout << "List kosong!" << endl;
        P = Nil;
        return;
    }

    P = L.First;

    if (L.First == L.Last)
    {
        L.First = Nil;
        L.Last = Nil;
    }
    else
    {
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }

    cout << "Kendaraan dengan nomor polisi " << P->info.nopol << " berhasil dihapus." << endl;

    dealokasi(P);
}


void deleteLast(List &L, address P)
{
    if (L.Last == Nil)
    {
        cout << "List kosong!" << endl;
        P = Nil;
        return;
    }

    P = L.Last;

    if (L.First == L.Last)
    {
        L.First = Nil;
        L.Last = Nil;
    }
    else
    {
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }

    cout << "Kendaraan dengan nomor polisi " << P->info.nopol << " berhasil dihapus." << endl;

    dealokasi(P);
}

void deleteAfter(address prec, address &P)
{
    string nopol;

    cout << "Masukkan nomor polisi yang ingin dihapus: ";
    getline(cin, nopol);

    if (prec == Nil)
    {
        cout << "List kosong!" << endl;
        P = Nil;
        return;
    }

    address Q = prec;

    while (Q->next != Nil &&
           Q->next->info.nopol != nopol)
    {
        Q = Q->next;
    }

    if (Q->next == Nil)
    {
        cout << "Nomor polisi tidak ditemukan!" << endl;
        P = Nil;
        return;
    }

    P = Q->next;

    Q->next = P->next;

    if (P->next != Nil)
    {
        P->next->prev = Q;
    }

    cout << "Data kendaraan berhasil dihapus:" << endl;
    cout << "Nomor polisi : " << P->info.nopol << endl;
    cout << "Warna        : " << P->info.warna << endl;
    cout << "Tahun        : " << P->info.thnBuat << endl;

    P->next = Nil;
    P->prev = Nil;

    dealokasi(P);
}

void deleteByNopol(List &L, string nopol)
{
    address P = L.First;

    while (P != Nil && P->info.nopol != nopol) {
        P = P->next;
    }

    if (P == Nil) {
        cout << "Nomor polisi tidak ditemukan!" << endl;
        return;
    }

    if (P == L.First) {
        L.First = P->next;

        if (L.First != Nil) {
            L.First->prev = Nil;
        } else {
            L.Last = Nil;
        }
    }
    else if (P == L.Last) {
        L.Last = P->prev;
        L.Last->next = Nil;
    }
    else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    cout << "Data dengan Nomor Polisi "<< P->info.nopol << " berhasil dihapus"<< endl;

    dealokasi(P);
}