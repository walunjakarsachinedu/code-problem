#include<bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    Node* children[26];
    bool isEndOfWord;
    Node(char val=' '):ch(val),isEndOfWord(false) {
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
};
class WordDictionary {
public:
    Node* head;
    WordDictionary():head(new Node()) {}
    
    void addWord(string word) {
        Node* node = head;
        for(int i=0;i<word.size();i++) {
            if(node->children[word[i]-97]==nullptr) node->children[word[i]-97] = new Node(word[i]);
            node = node->children[word[i]-97];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        return _search(word, head);
    }
private:
    bool _search(string word, Node* headNode) {
        Node* node = headNode;
        for(int i=0;i<word.size();i++) {
            if(word[i] == '.') {
                for(int j=0;j<26;j++) {
                    if(node->children[j])
                        if(_search(word.substr(i+1), node->children[j])) return true;
                }
                return false;
            }
            else if(node->children[word[i]-97]==nullptr) return false;
            node = node->children[word[i]-97];
        }
        return node->isEndOfWord;
    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("s");
    cout<<wordDictionary.search(".")<<endl;
    return 0;
}