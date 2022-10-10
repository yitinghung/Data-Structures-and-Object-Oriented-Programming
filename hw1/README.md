# OOP HW1 spec
## Problem 1: Big Integer
In this problem, you need to implement large integer arithmetic: addition, subtraction, multiplication, and division. You need to declare a class called “Large” and overload the following operator:
```
<<  |  Put to operator (cout)  
>>  |  From operator (cin)  
 +  |  Addition operator   
 -  |  Subtraction operator   
 *  |  Multiplication operator   
 /  |  Division operator   
 <  |  Less than operator  
 >  |  Greater than operator  
==  |  Equal operator  
 -  |  Negative operator  
```
In division, set the precision to the third digit after the decimal point.  
Hint: You can use string in your constructor

### Input
Your program should accept two large number through cin, so you need to overload “>>” operator.  
Test data will be in [-999999999999999999999999, 999999999999999999999999].  

### Output
You program should output those answer through cout, so you need to overload “<<” operator. And your program should support below operation with large number.

### Sample input
```
2222222222222222222222222
1111111111111111111111111
```
### Sample output
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
a * b = 2469135802469135802469135308641975308641975308642 
a / b = 2
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

## Problem 2: Polynomial
This problem asks you to create a class called Polynomial that includes the following functions:
```
* Calculate the value of polynomial.  
  $c_0x_n + c_1x_n−1 + ... + c_n−1x + c_n
* Calculate its first derivative.  
  $c_0nx_n−1 + c_1(n−1)x_n−2 + ... + c_n−1
* Calculate its second derivative.  
  $c_0n(n − 1)x_n−2 + c_1(n−1)(n−2)x_n−3 + ... + c_n−2
```

The class should have:
* A private member variable called x that holds the value of x.
```
int x;
```
* A private member variable called coef which is a vector type int holds the
coefficients of the polynomial.
```
vector<int> coef;
```
* A constructor that takes an int as input. Set x to the input integer and store the coefficients to the coef.  
* A function named calculate. The function should calculate the value of the polynomial.  
* A function named firstDerivative. The function should calculate the first order derivative of the polynomial.  
* A function named secDerivative. The function should calculate the second order derivative of the polynomial.  
The absolute value of all the input and output will be less than $2^31.  

### Input
Your program should accept an even number of lines of text. Each pair of lines will represent one problem. The first line will contain one integer: the value for x. The second line will contain a string, which represents a set of polynomial coefficients $(c_0, c_1, c_2, ..., c_n). Each coefficient will be seperated by one or more blanks.   
Input is terminated by EOF.  
 
### Output
For each pair of lines, your program should calculate the value of polynomial, the first order derivative of polynomial, and second order derivative of polynomial for the given value x and output it in a single line.

### Sample input
```

### Sample output
2
1 1 1
1
1  1  1

