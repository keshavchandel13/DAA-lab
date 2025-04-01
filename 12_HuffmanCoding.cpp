#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
struct Node{
    char ch;
    int freq;
    Node *left,*right;
    Node(char ch, int freq,Node *left=nullptr, Node *right=nullptr){
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};
struct compare{
    bool operator()(Node *a, Node *b){
        return a->freq > b->freq;
    }
};
Node* buildHuffmanTree(unordered_map<char,int>&freqMap){
    priority_queue<Node*,vector<Node*>,compare> minHeap; // Create a priority queue 
    // insert elements in priority queue
    for(auto ch:freqMap){
        minHeap.push(new Node(ch.first,ch.second));
    }
    // Build huffman tree
    while(minHeap.size()>1){
        Node *left = minHeap.top(); minHeap.pop(); 
        Node *right = minHeap.top(); minHeap.pop(); 
        Node * parent = new Node('\0',left->freq+right->freq,left,right);
        minHeap.push(parent);
    }
    return minHeap.top();
}
void generateCodes(Node *root, string code, unordered_map<char,string>&huffmanCode){
    if(!root) return;
    if(!root->left && !root->right){
        huffmanCode[root->ch] =code;
    }
    generateCodes(root->left,code+"0",huffmanCode);
    generateCodes(root->right,code+"1",huffmanCode);
}
string encodedText(string text, unordered_map<char,string>huffmanCode){
    string encoded = "";
    for(char ch :  text){
        encoded+=huffmanCode[ch];
    }
    return encoded;
}
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
int main(){
    string text = "ABBCCCDDDDEEEEE";
    unordered_map<char,int>  freqMap;
    for(char ch:text){
        freqMap[ch]++;
    }
    Node *root = buildHuffmanTree(freqMap);

    unordered_map<char,string> huffmanCode;
    generateCodes(root,"",huffmanCode);
    // Display
    for(auto pair:huffmanCode){
        cout<<pair.first<<" : "<<pair.second<<endl;
    }

    // Encode the text
    string encoded = encodedText(text,huffmanCode);
    cout<<encoded<<endl;
    freeTree(root);

    return 0;
}
