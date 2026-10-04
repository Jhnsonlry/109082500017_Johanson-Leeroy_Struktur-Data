#include <iostream>
using namespace std;

int main(){
    int i,j,k;

    int matrik1 [3][3]= {
        {2,4,3},
        {4,2,1},
        {5,2,3},
    };

    int matrik2 [3][3]= {
        {2,7,4},
        {3,8,5},
        {9,6,1},
    };
    int hasil[3][3] = {};

    cout<<"Penjumlahan Matriks: "<<endl;
    for (i= 0; i<3;i++){
        for (j = 0; j<3;j++){
            cout<< matrik1[i][j] + matrik2[i][j]<<" ";
        }
        cout<< "\n";
    }

    cout<<"\n";
    cout<<"Pengurangan Matriks: "<<endl;
    for (i= 0; i<3;i++){
        for (j = 0; j<3;j++){
            cout<< matrik1[i][j] - matrik2[i][j]<<" ";
        }
        cout<< "\n";
    }

    cout<<"\n";
    cout<<"Perkalian Matriks: "<<endl;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            for (k = 0; k < 3; k++){
                hasil[i][j] += matrik1[i][k] * matrik2[k][j];
            }
        }
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << "\n";
    }
}
