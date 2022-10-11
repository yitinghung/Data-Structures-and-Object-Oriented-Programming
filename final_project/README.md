# OOP Project Spec
## Description
You need to make a program named “compress.cpp” to compress a text file by using “Huffman Coding”. Then you need to make another program named “decompress.cpp” to decompress the compressed file.    
When you are compressing the file, you need to print the size of the file before compressed, and print the frequency of lowercase vowels of the whole text file.

## Input
* A text file as input. *  
Your program should use should use the filename as the argument value and compress the file. There is only one argument value only need to handle one file. The maximum input size won’t exceed 10MB.    
     
The command will be
'''
 ./compress xxxxx.txt    
'''

## Output
* Print the following message in the console: *
The first line is the size of file, and the unit of size is “Byte”    
The second line is frequency of “a” in the whole text file.     
The third line is frequency of “e” in the whole text file.     
The fourth line is frequency of “i” in the whole text file.      
The fifth line is frequency of “o” in the whole text file.     
The sixth line is frequency of “u” in the whole text file.       


Save the compressed file named xxxxx.compress (the original file is xxxxx.txt). The storage location of the compressed file is same as your program.     

* Output message example: *
```
62
5
6
7 8 9
```

## Example
When you compress a text file     
Example:
| Input command         | Output message  |
|-----------------------|-----------------|
|./compress filename.txt|62               |
|                       |5                |
|                       |6                |
|                       |7                |
|                       |8                |
|                       |9                |  
|                       |Output file      |
|                       |filename.compress|
        
When you decompress a compressed file
|Input command                  | Output file               |
|-------------------------------|---------------------------|
|./decompress filename.compress | filename_decompressed.txt |
     
The file’s content before compression and the file’s content after decompression are exactly the same.
