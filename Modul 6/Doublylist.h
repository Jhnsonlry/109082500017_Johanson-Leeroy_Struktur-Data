#ifndef LISTKENDARAAN_H
#define LISTKENDARAAN_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct kendaraan infotype;

typedef struct ElmList *address;

struct kendaraan
{
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList
{
    infotype info;
    address next;
    address prev;
};

struct List
{
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address &P);
void findElm(List L, infotype x);
void deleteFirst(List &L, address P);
void deleteLast(List &L, address P);
void deleteAfter(address prec, address &P);
void deleteByNopol(List &L, string nopol);
#endif
