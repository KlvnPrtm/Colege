#include <iostream>
#include <string>
using namespace std;

int main(){
    char Nama[50]={"Rafiq Widya Pratama"};
    char Nim[50]={"231011700153"};
    char Kelas[50]={"01SIFP003"};
    int Bilangan;
    cout << "Nama : " << Nama << endl;
    cout << "Nim  : " << Nim << endl;
    cout << "Kelas: " << Kelas << endl;
    cout << "======================" << endl;
    
    cout << "Masukan Bilangan : ";
    cin >> Bilangan;
    Bilangan = Bilangan % 2;
    cout << "Sisa Bagi : " << Bilangan << endl;
    if (Bilangan == 0){
        cout << "adalah bilangan genap" << endl;
    }
    else if (Bilangan == 1){
        cout << "adalah bilangan ganjil" << endl;
    }

    cout << "----------------------" << endl;
    
    cout << "Masukan Bilangan : ";
    cin >> Bilangan;
    Bilangan = Bilangan % 2;
    cout << "Sisa Bagi : " << Bilangan << endl;
    if (Bilangan == 0){
        cout << "adalah bilangan genap" << endl;
    }
    else if (Bilangan == 1){
        cout << "adalah bilangan ganjil" << endl;
    }
    
    cout << "----------------------" << endl;
    
    return 0;
}
