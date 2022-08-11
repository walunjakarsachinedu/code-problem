#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    char val = ' ';
    vector<Node*> children = vector<Node*>(26, nullptr);
    bool isEndOfWord = false;
    Node() {}
    Node(char ch): val(ch) {};
    
    Node*& getNode(char ch) {
        return children[ch-97];
    }
};

class Trie {
public:
    Node* head;
    Trie():head(new Node()) {}

    void insert(string word) {
        Node *node = head;
        for(int i=0;i<word.size();i++) {
            if(node->children[word[i]-97]==nullptr) 
                node->children[word[i]-97] = new Node(word[i]);
            node = node->getNode(word[i]);
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        Node *node = head;
        for(int i=0;i<word.size();i++) {
            if(node==nullptr) return false;
            node = node->getNode(word[i]);
        }
        if(node->isEndOfWord) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *node = head;
        for(int i=0;i<prefix.size();i++) {
            if(node==nullptr) return false;
            node = node->getNode(prefix[i]);
        }
        return true;
    }
};

int main() {
    Trie* trie = new Trie();
    trie->insert("sachin");
    cout<<trie->startsWith("sachin")<<endl;
    return 0;
}