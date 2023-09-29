#include <iostream>

using namespace std;

int main(){

    //bilangan bulat
    int a = 1;
    long b = 7;
    short c = 8;

    //bilangan decimal
    float d = 1.0;
    double e = 2.5;

    //character
    char f = 'z'; //character 1-bit

    //boolean
    bool g = true; // true/false

    cout << f << endl;
    cout << sizeof(b) << " byte" << endl;
    //cout << numeric_limits<long> ::max() <<endl;
    //cout << numeric_limits<long> ::min() <<endl;

    return 0;
}