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