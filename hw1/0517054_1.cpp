#include <iostream>
#include "0517054_1.hpp"
using namespace std;

int main() {
    Large a, b;
    cout << "Please ENTER two number a and b: ";
    cin >> a >> b;
    cout << endl;
    cout << "a = " << a << endl;
    cout << "-a = " << -a << endl;
    cout << "b = " << b << endl;
    cout << "-b = " << -b << endl << endl;
    cout << "a > b ? " << (a > b) << endl;
    cout << "a < b ? " << (a < b) << endl;
    cout << "a = b ? " << (a == b) << endl << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    return 0;
}
