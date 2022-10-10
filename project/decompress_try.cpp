#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const long long MAX_MEMORY = 10 * 1024 * 1024;
const int KIND_OF_CHARACTER = 260;
/*
struct Node{
    int c;
    long long number;
    char Huffmancode[100];
}node[260];
*/

struct Node {
    int c; // character
    int parent, lChild, rChild;//children node
    int iNode; //the serial number of node
    long long number; //number of corresponding character
    char Huffmancode[100];
    friend bool operator < (Node a, Node b) {
        return a.number > b.number;
    }
}node[260];

int  nBits = 8;
int bits;
int numberOfNode;
int bitsAdded;
int OFFSET=20;

int BuildHuffmanTree(){
    //apply 2 * KIND_OF_CHARACTER to store nodes of the Huffman tree
    Node* HT = (Node *)malloc((2 * KIND_OF_CHARACTER) * sizeof(Node));
    //put all kinds of character into priority queue
    priority_queue<Node> q;
    int  inode = 0;
    for (int i = 0; i < numberOfNode; i++) {
        node[i].iNode = inode;
        q.push(node[i]);
        HT[inode] = node[i];
        inode++;
    }
    
    int jNode = numberOfNode;
    while (q.size() > 1){
        //get two minimal weight nodes and set their parent
        Node leftNode = q.top();
        q.pop();
        Node rightNode = q.top();
        q.pop();
        //cout <<" ##"<< leftNode.number <<endl;
        //cout <<" **"<< rightNode.number <<endl;
        int l = leftNode.iNode;
        int r = rightNode.iNode;
        HT[l].parent = jNode;
        HT[r].parent = jNode;
        //set parent's  information
        HT[jNode].c = ' ';
        HT[jNode].iNode = jNode;
        HT[jNode].lChild = l;
        HT[jNode].rChild = r;
        HT[jNode].number = leftNode.number + rightNode.number;
        q.push(HT[jNode]);
        jNode++;
    }
    HT[jNode-1].parent = -1;
    
    
    
    //cout<<HT[jNode-1].number<<endl;
    free(HT);
    return numberOfNode;
}


int main() {
    char compressFilePath[20] = "test2.txt"; //graph.txt  "1.txt";
    char decompressFilePath[50] = "test_decompressed.txt";
    ifstream readIn;
    readIn.open(compressFilePath, ios::binary);
    if (readIn.is_open() == 0) {
        cout << "OPEN FAILED!" << endl;
        exit(0);
    }
    ofstream writeOut;
    writeOut.open(decompressFilePath, ios::binary);
    if (writeOut.is_open() == 0) {
        cout << "OPEN FAILED!" << endl;
        exit(0);
    }
    
    FILE *fin, *fout;
    fin = fopen("test2.txt", "r");
    fout = fopen("text2_decompress.txt", "w");
    fscanf(fin, "%d", &numberOfNode);
    cout<<"numberOfNode:"<<numberOfNode<<endl;
    
    int maxEncodingLength = 0;
    for (int i = 0; i < numberOfNode; i++) {
        fscanf(fin, "%d %lld %s", &node[i].c, &node[i].number, node[i].Huffmancode);
        //fgets(node[i].Huffmancode, bits, fin);
        
        cout << node[i].c << " " << node[i].number<<" "<<node[i].Huffmancode << endl;
    }
    //get information of compressed file
    BuildHuffmanTree();
    int d;
    while(!feof(fin)) {
        fread(&d, sizeof(int), 1, fin);
        printf("%c", d);
    }
    //decompress File
    //DecompressFile(readIn, writeOut, maxEncodingLength);

    return 0;
}

