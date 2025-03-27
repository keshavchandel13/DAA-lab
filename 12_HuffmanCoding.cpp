#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
        left = right = nullptr;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Compare frequencies
    }
};

Node* huffman_tree(unordered_map<char, int>& freqmap) {
    priority_queue<Node*, vector<Node*>, compare> minheap;

    for (auto pair : freqmap) {
        minheap.push(new Node(pair.first, pair.second)); // Push nodes into min-heap
    }

    while (minheap.size() > 1) {
        Node* left = minheap.top(); minheap.pop();
        Node* right = minheap.top(); minheap.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        minheap.push(merged);
    }

    return minheap.top(); // Return the root of the Huffman Tree
}

void generateCodes(Node* root, string code, unordered_map<char, string>& huffCodes) {
    if (!root) return;

    // If leaf node, store the character with its corresponding code
    if (root->ch != '\0') {
        huffCodes[root->ch] = code;
    }

    // Recur for left and right subtrees
    generateCodes(root->left, code + "0", huffCodes);
    generateCodes(root->right, code + "1", huffCodes);
}

int main() {
    string s = "aaabbcc";  // Input string

    // Frequency map to track repetition of characters
    unordered_map<char, int> freqmap;
    for (auto ch : s) {
        freqmap[ch]++;
    }

    // Create Huffman's tree
    Node* root = huffman_tree(freqmap);

    unordered_map<char, string> huffCodes;
    generateCodes(root, "", huffCodes); // Generate Huffman codes for each character

    // Display Huffman Codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffCodes) {
        cout << pair.first << " : " << pair.second << "\n";
    }

    // Encode the original text
    string encoded = "";
    for (char ch : s) {
        encoded += huffCodes[ch]; // Get the Huffman code for each character
    }

    cout << "Encoded text: " << encoded << endl;

    return 0;
}
