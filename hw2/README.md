# OOP HW2 Spec
## Description
One day, your boss gave you a machine to solve both a “string” and a “math” problem. But all the code in this machine was empty. Now, you are asked to inherit the parent class named “Machine” and complete the virtual function in its child classes.
You need to use Virtual Function and Polymorphism to finish the homework. If you don’t follow the rule, you will get 0 point even though the answers are correct.
Just add your codes in assigned area and necessary header files, otherwise, you will get 0 point. You can create other functions in child class if you want.

## The Math Problem
Given an integer “x”, you need to find two integers whose product is equal to “x” or “x+1” and these two integers have minimum absolute difference. Then, print these two integers as your output.  

### Explanation
When input is: 3   
[tab]x=3  
[tab][tab]1\*3=3 → absolute difference is 2    
[	]x+1=4     
[tab][tab]1\*4=4 → absolute difference is 3    
[tab][tab]2\*2=4 → absolute difference is 0     
      
Hence these two integers (2 and 2) have the minimum absolute difference 0 when input is 3.   

### Input
Your program should accept an integer in the range between $1$ to $2^{16}-1$.  

For example:   
124

### Output  
Print two integers which have minimum absolute difference. Print the smaller integer first if the two integers are not the same. Besides, there is a space between these two integers.  

For example:   
5 25   


## The String Problem    
Given a string “str” which represent a binary number.     
You’re required to find all substrings which have the same numbers of 0’s and 1’s within the substring. Besides, all 0’s in the substring should be grouped together in the substring, without being separated by any 1’s. e.g.001100 is not allowed. Same restrictions above apply to 1’s, where 1’s in the substring cannot be separated by 0’s. Print the total amount of substrings that you find that fulfills the requirements listed above.     

Note:   
* Substring cannot be empty.    
* Same substring may occur many times, you need to count all of them.   
* The entire string is a substring, too. Don’t forget to check whether it fulfills requirement or not.    

### Explanation   
When input is: “11001100“  
The substring satisfying the limitations include:     
“1100” (11001100)、”10” (11001100)   
”0011” (11001100)、”01” (11001100)   
”1100” (11001100)、“10” (11001100).     
The total amount of these substring is 6. As a result, the answer is 6.     

### Input
Your program should accept a string.    
The total length of input string is between 1 and 10000. The characters in the input string only contain 0 and 1.    
     
For example:    
1111100000    

### Output
Print how many substrings satisfying the limitation.    
     
For example:      
5     

## Make your Machine to solve above problems
### Main function Description
Once your machine receives a message “math” by user, it will call the **welcome_message** function to print corresponding message, then use the next input as the parameter of “**problem_solver**” virtual function in the class “**Math_machine**” to solve the problem.    
On the contrary, if your program receives a message “string”, call the **welcome_message** function to print corresponding message, then use the next input as the parameter of “**problem_solver**” virtual function in the class “**String_machine**” to solve the problem.     
     
Make your program solve the corresponding problem until terminated by EOF.    

### Math and String Class Description     
**constructor:** Initialize the protected variable for the machine. (“Math” or “String”)      
**welcome_message:** Print the welcome message. The message format has been defined inside the function.      
**problem_solver:** Solve the corresponding problem for string or math and print the answer.    

### Sample Input 1
```
math
124
string
10101
math
1000
string
111001
```
### Sample Output 1    
```
Solving the math problem. 
5 25
Solving the string problem. 
4
Solving the math problem. 
25 40
Solving the string problem. 
3
```

### Sample Input 2
```
string
110011
math
333
math
17
string
1100
```

### Sample Output 2 
```
Solving the string problem. 
4
Solving the math problem. 
9 37
Solving the math problem. 
36
Solving the string problem. 
2


