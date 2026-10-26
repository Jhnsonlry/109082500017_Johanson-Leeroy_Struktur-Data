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
