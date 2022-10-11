# OOP HW3 spec
## Description
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

## Input
Your program is supposed to be able to handle “`int`” and “`double`” format First value represents the datatype of test data:   
if it’s 1, the input will be integer; otherwise, double.   
Then use the command below to manipulate the vector until command=0.
| Command | Description |
| ------- | ----------- |
|1        | my_push_back|
|2        | my_insert   |
|3        | my_set      |
|4        | my_reverse  |
|5        | my_pop_back |
|6        | my_clear    |
|0        | Print the info and quit|

## Ouput
Your program should support two different ways to print the vector. First is using print function. Second is using cout and operator [] to print the whole vector. Last, print the information of the vector by the function “my_empty” to test whether the vector is empty or not.

## Sample Input 1
```
1   
1 1 0   
1 2 0   
1 3 0    
1 4 0      
2 22 2     
3 33 3     
5 0 0    
4 0 0     
0 0 0     
```

## Sample Output 1
```
33_22_2_1_    
33_22_2_1_     
Not Empty     
```

## Sample Input 2
```
2    
1 1 0   
1 1.5 0     
6 0 0     
1 -99.9 0    
0 0 0    
```

## Sample output 2:
```
-99.9_    
-99.9_     
Not Empty     
```

