#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
const long long MAX_MEMORY = 10 * 1024 * 1024;
const int offset = 20;
const int nBits = 8;

struct Node {
    char c;
    int top, left, right;
    int i;
    long long number;
    friend bool operator < (Node a, Node b) {
        return a.number > b.number;
    }
}node[260];

char Huffman_Code[260][1000];

int Build_HT(){
    Node* HT = (Node *)malloc((2 * 260) * sizeof(Node));
    priority_queue<Node> q;
    int  num_Node = 0;
    for (int i = 0; i < 260; i++) {
        if (node[i].number != 0) {
            node[i].i = num_Node;
            node[i].c = i;
            q.push(node[i]);
            HT[num_Node] = node[i];
            num_Node++;
        }
    }
    
    cout << node['a'].number<<endl;
    cout << node['e'].number<<endl;
    cout << node['i'].number<<endl;
    cout << node['o'].number<<endl;
    cout << node['u'].number<<endl;
    
    int jNode = num_Node;
    while (q.size() > 1){
        Node leftNode = q.top();
        q.pop();
        Node rightNode = q.top();
        q.pop();
        int left = leftNode.i;
        int right = rightNode.i;
        HT[left].top = jNode;
        HT[right].top = jNode;
        HT[jNode].c = ' ';
        HT[jNode].i = jNode;
        HT[jNode].left = left;
        HT[jNode].right = right;
        HT[jNode].number = leftNode.number + rightNode.number;
        q.push(HT[jNode]);
        jNode++;
    }
    HT[jNode-1].top = -1;
    
    for (int i = 0; i < num_Node; i++) {
        int k = 0;
        int l = i;
        char ch = HT[i].c;
        for (int j = HT[i].top; j != -1; j = HT[j].top) {
            if (HT[j].left == l) {
                Huffman_Code[ch][k] = '0';
            }
            else {
                Huffman_Code[ch][k] = '1';
            }
            l = j;
            k++;
        }
        for (int j = 0; j < k / 2; j++) {
            char temp = Huffman_Code[ch][j];
            Huffman_Code[ch][j] = Huffman_Code[ch][k-1-j];
            Huffman_Code[ch][k-1-j] = temp;
        }
        Huffman_Code[ch][k] = '\0';
        
    }
    free(HT);
    return num_Node;
}
void Bit_to_Int(ofstream &outPut, char* HTstr, long long len) {
    int k = 0;
    if (len % nBits != 0) {
        int bitsToAdd = nBits - (len % nBits);
        streampos pos = outPut.tellp();
        outPut.seekp(0, ios::beg);
        outPut.write((char *)&bitsToAdd, sizeof(int));
        outPut.seekp(pos, ios::beg);
        for (; k < bitsToAdd; k++){
            HTstr[len+k] = '0';
        }
        HTstr[len+k] = '\0';
        
    }
    
    int pow = 1<<(nBits - 1);
    int sum = 0;
    for (long long i = 0, j = 0; i < len+k && HTstr[i]; i++) {
        if (j == nBits){
            outPut.write((char *)&sum, sizeof(char));
            j = 0;
            sum = 0;
        }
        sum += (HTstr[i]-'0') * (pow >> j);
        j++;
    }
    
    outPut.write((char *)&sum, sizeof(char));
}
void CompressFile(const char *file, const char *outfile, int num_Node, long long fileSize){
    ifstream readIn;
    readIn.open(file, ios::binary);
    
    ofstream outPut;
    outPut.open(outfile, ios::binary);
    
    outPut.seekp(offset, ios::beg);
    outPut.write((char *)&num_Node, sizeof(int));
    for (int i = 0; i < 260; i++) {
        if (node[i].number != 0) {
            outPut.write((char *)&i, sizeof(char));
            int bits = strlen(Huffman_Code[i]);
            outPut.write((char *)&bits, sizeof(int));
            outPut.write((char *)&Huffman_Code[i], bits*sizeof(char));
        }
    }
    
    
    int nTimes = (int)(fileSize / MAX_MEMORY);
    if (fileSize % MAX_MEMORY != 0) nTimes++;
    char *HTstr = (char *)calloc(1, (MAX_MEMORY+1000)*sizeof(char));
    int len = 0;
    long long lenT = 0;
    for (int i = 1; i <= nTimes; i++) {
        char *str = (char *)calloc(1, (MAX_MEMORY+10)*sizeof(char));
        long long num_Char = MAX_MEMORY;
        if (i == nTimes) {
            num_Char = fileSize % MAX_MEMORY;
        }
        readIn.read(str, num_Char * sizeof(char));
        str[num_Char] = '\0';
        for (long long j = 0; j < num_Char; j++) {
            char ch = str[j];
            lenT += strlen(Huffman_Code[ch]);
            strcpy(HTstr+len, Huffman_Code[ch]);
            len += strlen(Huffman_Code[ch]);
            
            if (len > MAX_MEMORY) {
                long long leftBits = len % nBits;
                long long changeLength = len - leftBits;
                Bit_to_Int(outPut, HTstr, changeLength);
                
                strcpy(HTstr,  HTstr+changeLength);
                len = strlen(HTstr);
            }
        }
        free(str);
    }
    if (len != 0) {
        Bit_to_Int(outPut, HTstr, len);
    }
    free(HTstr);
    readIn.close();
    outPut.close();
}



int main(int argc, char *argv[]) {

    char File_decompressed[50];
    int i;
    for(i=0; i<50; i++){
        if(argv[1][i] == '.')
            break;
        File_decompressed[i] = argv[1][i];
    }
    File_decompressed[i] = '\0';
    strcat(File_decompressed, ".compress");
    
    ifstream readIn;
    readIn.open(argv[1], ios::binary);
    
    readIn.seekg(0, ios::end);
    long long fileSize = (long long)readIn.tellg();
    readIn.seekg(0, ios::beg);
    cout<<fileSize<<endl;
    
    int nTimes = (int)(fileSize / MAX_MEMORY);
    if (fileSize % MAX_MEMORY != 0) nTimes++;
    for (int i = 1; i <= nTimes; i++) {
        char *str = (char *)calloc(1, (MAX_MEMORY+10)*sizeof(char));
        
        long long num_Char = MAX_MEMORY;
        if (i == nTimes) {
            num_Char = fileSize % MAX_MEMORY;
        }
        readIn.read(str, num_Char * sizeof(char));
        str[num_Char] = '\0';
        
        int lenStr = strlen(str);
        for (long long j = 0; j < lenStr; j++) {
            node[str[j]].number++;
            node[str[j]].c = str[j];
        }
        free(str);
    }
    
    int num_Node = Build_HT();
    CompressFile(argv[1], File_decompressed, num_Node, fileSize);
    readIn.close();
}



