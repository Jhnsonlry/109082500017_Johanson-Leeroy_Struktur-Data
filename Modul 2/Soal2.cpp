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
    int a = 2, b = 3, c = 7;

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
    