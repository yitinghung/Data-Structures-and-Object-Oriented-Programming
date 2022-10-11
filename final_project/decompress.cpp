#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node{
    char c;
    char Huffman_code[1000];
}node[260];

int main(int argc, char *argv[]) {
    char File_decompressed[50];
    int i;
    for(i=0; i<50; i++){
        if(argv[1][i] == '.')
            break;
        File_decompressed[i] = argv[1][i];
    }
    File_decompressed[i] = '\0';
    strcat(File_decompressed, "_decompressed.txt");
    
    ifstream readIn;
    readIn.open(argv[1], ios::binary);
    
    ofstream writeOut;
    writeOut.open(File_decompressed, ios::binary);
    
    const long long MAX_MEMORY = 10 * 1024 * 1024;
    int  nBits = 8;
    int num_Node;
    int bitsAdded;
    int offset=20;
    
    readIn.read((char *)&bitsAdded, sizeof(int));
    readIn.seekg(offset, ios::beg);
    readIn.read((char *)&num_Node, sizeof(int));
    for (int i = 0; i < num_Node; i++) {
        readIn.read((char *)&node[i].c, sizeof(char));
        int bits;
        readIn.read((char *)&bits, sizeof(int));
        readIn.read((char *)&node[i].Huffman_code, bits*sizeof(char));
        node[i].Huffman_code[bits] = '\0';
    }
    
    streampos curPos = readIn.tellg();
    readIn.seekg(0, ios::end);
    long long filesize = (long long)(readIn.tellg() - curPos);
    readIn.seekg(curPos, ios::beg);
    
    int nTimes = (int)(filesize / MAX_MEMORY);
    if (filesize % MAX_MEMORY != 0) nTimes++;
    char *str = (char *)calloc(1, (MAX_MEMORY + 1000)* sizeof(char));
    int lenOfChar = 0;
    for (int j = 1; j <= nTimes; j++) {
        long long num_char = MAX_MEMORY;
        if (j == nTimes) {
            num_char = filesize % MAX_MEMORY;
        }
        char *temp = (char *)calloc(1, (2*1000) * sizeof(char));
        char *buf = (char *)calloc(1, (MAX_MEMORY + 1000)* sizeof(char));
        
        readIn.read(buf, num_char * sizeof(char));
        
        int len_temp = 0;
        for (int k = 0; k < num_char; k++) {
            unsigned char ascII = buf[k];
            char huffstr[3*nBits];
            
            for (int i = nBits - 1; i >= 0; i--) {
                huffstr[i] = ascII % 2 + '0';
                ascII = ascII / 2;
            }
            if ((j == nTimes) && (k == num_char - 1)) {
                nBits = nBits - bitsAdded;
            }
            huffstr[nBits] = '\0';
            
            strcpy(temp + len_temp, huffstr);
            len_temp += strlen(huffstr);
            
            for(;;) {
                int flag = 0;
                for (int z = 0; z < num_Node; z++) {
                    
                    int len = strlen(node[z].Huffman_code);
                    if (!memcmp(node[z].Huffman_code, temp, len)) {
                        str[lenOfChar] = node[z].c;
                        str[lenOfChar+1] = '\0';
                        lenOfChar ++;
                        
                        strcpy(temp, temp+len);
                        len_temp = strlen(temp);
                        
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0 || (len_temp == 0)) break;
            }
            
            
            if (lenOfChar > MAX_MEMORY) {
                writeOut.write(str, lenOfChar * sizeof(char));
                strcpy(str, "");
                lenOfChar = 0;
            }
        }
        free(buf);
        free(temp);
    }
    if (lenOfChar != 0){
        writeOut.write(str, lenOfChar * sizeof(char));
        free(str);
    }
    
    readIn.close();
    writeOut.close();
    return 0;
}

