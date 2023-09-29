#include <iostream>

using namespace std;

int main(){
    int a;

    cout << "masukan angka = ";
    cin >> a;

    if (a == 3){   
        cout << "nilai 3" << endl;
    }else if ( a == 4) {
        cout << "nilai 4" << endl;
    }else if ( a == 1){
        cout << "nilai 1" << endl;
    }else {
        cout << "bukan 3,4, atau 1" << endl;
    }

    cout << "selesai" << endl;

    return 0;
}