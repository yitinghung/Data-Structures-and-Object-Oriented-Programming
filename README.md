# Data Structures and Object-oriented Programming 
NCTU CS Course lectured by PhD. Jiun-Long Huang (2019 Spring)

##[OOP HW 1](https://github.com/yitinghung/Data-Structures-and-Object-Oriented-Programming/tree/main/hw1)
1. Big Integer    
Implement large integer arithmetic: addition, subtraction, multiplication, and division.    
Declare a class called “Large” and overload the following operator:      
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
Usage
```
g++ 0517054_1.cpp -o 0517054_1
./0517054_1
```

2. Polynomial   
Create a class called Polynomial that includes the following functions:
* Calculate the value of polynomial.
  $c_0x_n + c_1x_n−1 + ... + c_n−1x + c_n$
* Calculate its first derivative.
  $c_0nx_n−1 + c_1(n−1)x_n−2 + ... + c_n−1$
* Calculate its second derivative.
  $c_0n(n − 1)x_n−2 + c_1(n−1)(n−2)x_n−3 + ... + c_n−2$
Usage
```
g++ 0517054_2.cpp -o 0517054_2
./ 0517054_2
```

##[OOP HW 2](https://github.com/yitinghung/Data-Structures-and-Object-Oriented-Programming/tree/main/hw2)
Solve both a “string” and a “math” problem by inherit the parent class named “Machine” and complete the virtual function in its child classes. (Use Virtual Function and Polymorphism)       
1. The Math Problem     
Given an integer “x”, find two integers whose product is equal to “x” or “x+1” and these two integers have minimum absolute difference.       
2. The String Problem      
Given a string “str” which represent a binary number.      
Find all substrings which have the same numbers of 0’s and 1’s within the substring. Besides, all 0’s in the substring should be grouped together in the substring, without being separated by any 1’s. e.g.001100 is not allowed. Same restrictions above apply to 1’s, where 1’s in the substring cannot be separated by 0’s      
Usage
```
g++ 0517054.cpp -o 0517054
./0517054
```

##[OOP HW 3](https://github.com/yitinghung/Data-Structures-and-Object-Oriented-Programming/tree/main/hw3)
Create a simple template class name SimpleVector which simulates different vector types and contains functions below:    
* `Constructor`: set the initial vector. If the vector length is not assigned, then set the maximum capacity of vector to 5.
* `Destructor`: delete the vector.
* `my_empty`: return 1 if the vector element is empty, otherwise return 0.
* `my_size`: return the number of elements that exist value in the vector.
* `my_reverse`: reverse all the elements in the vector by their positions.
* `my_clear`: set all existing elements to '\0' that means no value.
* `my_extend`: increases the capacity to “two times of the current capacity” of the dynamically created array.
* `my_push_back`: assign the value to the last element of the array with the user input value. If the vector’s size isn’t enough, then extend the array.
* `my_pop_back`: pop out the last element of the vector.
* `my_insert`: insert an element with value and index provided by user. Extend the array if the vector’s size isn’t enough. If the index input is out
of the vector’s size, then don’t do anything.
* `my_set`: replace an element with value and index provided by user. If the index input is out of the vector’s size, then don’t do anything.
* `print`: display all the elements in the vector separated by “_”. Besides, try to overload the operator [] that returns the value of the vector for the specific index. E.g. sample[5] returns the sixth element of the sample vector. If the input index is out of the vector length, then return the last element of the vector.

Usage
```
g++ main.cpp -o main
./main
```

##[OOP Final Project](https://github.com/yitinghung/Data-Structures-and-Object-Oriented-Programming/tree/main/final_project)
1. Make a program named “compress.cpp” to compress a text file by using “Huffman Coding”.    
2. Make another program named “decompress.cpp” to decompress the compressed file.     
\*Print the size of the file before compressed, and print the frequency of lowercase vowels of the whole text file when compressing the file

Usage
```
cd final_project
g++ compress.cpp -o compress
g++ decompress.cpp -o decompress
./compress test.txt              
./decompress test.compress
```
