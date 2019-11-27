#include<bits/stdc++.h>
#include<conio.h>
#include<process.h>
#include<Windows.h>
#include<fstream>
#include<map>
//#include "Huffman.h"
//#include<chrono>
#include<ctime>
using namespace std;
#define MAX_TREE_HT 256 
map<char, string> codes; 
// to store the frequency of character of the input data 
map<char, int> freq; 
// A Huffman tree node 
struct MinHeapNode 
{ 
    char data;             // One of the input characters 
    int freq;             // Frequency of the character 
    MinHeapNode *left, *right; // Left and right child 
  
    MinHeapNode(char data, int freq) 
    { 
        left = right = NULL; 
        this->data = data; 
        this->freq = freq; 
    } 
};   
// utility function for the priority queue 
struct compare 
{ 
    bool operator()(MinHeapNode* l, MinHeapNode* r) 
    { 
        return (l->freq > r->freq); 
    } 
}; 
  
// utility function to print characters along with 
// there huffman value 

// utility function to store characters along with 
// there huffman value in a hash table, here we 
// have C++ STL map 
void storeCodes(struct MinHeapNode* root, string str) 
{ 
    if (root==NULL) 
        return; 
    if (root->data != '$') 
        codes[root->data]=str; 
    storeCodes(root->left, str + "0"); 
    storeCodes(root->right, str + "1"); 
} 
  
// STL priority queue to store heap tree, with respect 
// to their heap root node value 
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 
  
// function to build the Huffman tree and store it 
// in minHeap 
void HuffmanCodes(int size) 
{ 
    struct MinHeapNode *left, *right, *top; 
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++) 
        minHeap.push(new MinHeapNode(v->first, v->second)); 
    while (minHeap.size() != 1) 
    { 
        left = minHeap.top(); 
        minHeap.pop(); 
        right = minHeap.top(); 
        minHeap.pop(); 
        top = new MinHeapNode('$', left->freq + right->freq); 
        top->left = left; 
        top->right = right; 
        minHeap.push(top); 
    } 
    storeCodes(minHeap.top(), ""); 
} 
  
// utility function to store map each character with its 
// frequency in input string 
void calcFreq(string str, int n) 
{ 
    for (int i=0; i<str.size(); i++) 
        freq[str[i]]++; 
} 
  
// function iterates through the encoded string s 
// if s[i]=='1' then move to node->right 
// if s[i]=='0' then move to node->left 
// if leaf node append the node->data to our output string 