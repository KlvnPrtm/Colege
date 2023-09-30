#include <iostream>

using namespace std;

int main(){
    
    int a = 5;
    int b = 4;

    int hasil;
    // +-*/%
    hasil = a + b;
    cout << a << " + " << b << " = " << hasil  << endl;

    hasil = a - b;
    cout << a << " - " << b << " = " << hasil  << endl;

    hasil = a * b;
    cout << a << " * " << b << " = " << hasil  << endl;

    hasil = a / b;
    cout << a << " / " << b << " = " << hasil  << endl;
    
    hasil = a % b;
    cout << a << " % " << b << " = " << hasil  << endl;

    hasil = (a + b) * a;
    cout << hasil << endl;

    return 0;
}