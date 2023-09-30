#include <iostream>

using namespace std;

int main (){

    float a,b,hasil;
    char aritmatika;

    cout << "Selamat Datang Di Program Calculator \n \n";

    cout << "Masukan Nilai = ";
    cin >> a;
    cout << "Pilih Operator +,-,/,* = ";
    cin >> aritmatika;
    cout << "Masukan Nilai = ";
    cin >> b;

    cout << "\nHasil Perhitungan: ";
    cout << a << aritmatika << b;

    switch(aritmatika) {
        case '+':
            hasil = a + b;
            break;
        case '-':
            hasil = a - b;
            break;
        case '/':
            hasil = a / b;
            break;
        case '*':
            hasil = a * b;
            break;
        default:
            cout << "default" << endl;
    }

    cout << " = " << hasil << endl;

    return 0;
}