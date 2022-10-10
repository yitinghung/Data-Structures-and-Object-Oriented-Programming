# OOP HW1 spec
## Problem 1: Big Integer
In this problem, you need to implement large integer arithmetic: addition, subtraction, multiplication, and division. You need to declare a class called “Large” and overload the following operator:
```
<< | Put to operator (cout) (10%)
>> | From operator (cin) (10%)
 + | Addition operator (10%)
 - | Subtraction operator (10%)
 * | Multiplication operator (20%)
 / | Division operator (20%)
 < | Less than operator (5%)
 > | Greater than operator (5%)
== | Equal operator (5%)
 - | Negative operator (5%) 
```
In division, set the precision to the third digit after the decimal point.
Hint: You can use string in your constructor

## Input
Your program should accept two large number through cin, so you need to overload “>>” operator.
Test data will be in [-999999999999999999999999, 999999999999999999999999].

## Output
You program should output those answer through cout, so you need to overload “<<” operator. And your program should support below operation with large number.

## Sample input
```
2222222222222222222222222
1111111111111111111111111
```
## Sample output
```
a = 2222222222222222222222222
-a = -2222222222222222222222222
b = 1111111111111111111111111
-b = -1111111111111111111111111
a > b ? True
a < b ? False
a = b ? False
a + b = 3333333333333333333333333
a – b = 1111111111111111111111111
a * b = 2469135802469135802469135308641975308641975308642 a/ b = 2
```

Following code is an easy sample to test your assignment:
```
#include <iostream>
#include "08XXXXX_1.hpp"
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
```
