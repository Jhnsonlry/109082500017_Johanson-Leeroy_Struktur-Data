#include "Doublylist.h"

int main()
{
    List L;
    address P;
    address prec = L.First;
    infotype x;

    CreateList(L);

    insertLast(L, P);
    insertLast(L, P);
    insertLast(L, P);
    insertLast(L, P);

    printInfo(L);
    cout<< endl;
    findElm(L, x);
    cout<< endl;
    string nopol;

    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    getline(cin, nopol);

    deleteByNopol(L, nopol);
    cout<<endl;
    printInfo(L);

    return 0;
}
