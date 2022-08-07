#include<bits/stdc++.h>
using namespace std;


struct Node {
    int val;
    int key;
    Node* prev;
    Node* next;
    Node() {}
    Node(int key, int val) : val(val), key(key), prev(nullptr), next(nullptr)  {}

    ///Order of parameter matter most in this function
    static void addLink(Node* a, Node* b) {
        if(a) a->next = b;
        if(b) b->prev = a;
    }
};

struct LinkedList {
    Node* front;
    Node* back;
    LinkedList(): front(nullptr), back(nullptr) {}

    void addToBack(Node* node) {
        Node::addLink(back, node);
        back = node;
        node->next = nullptr;
        if(front == nullptr) front = back;
    }

    void moveToBack(Node* node) {
        if (node != back) { // moving node to back
            if (node == front) front = front->next;
            else Node::addLink(node->prev, node->next); // removing element
            addToBack(node);
        }
    }

    void print(bool forward) {
        if(forward) {
            Node* node = front;
            while(node) {
                cout<<"("<<node->key<<":"<<node->val<<") ";
                node = node->next;
            }
        } else {
            Node* node = back;
            while(node) {
                cout<<node->val<<" ";
                node = node->prev;
            }
        }
        cout<<endl;
    }
};
// most recently used node is  most recently add, updated, getted
class LRUCache {
public:
    int capacity;
    unordered_map<int,Node*> hashMap;
    LinkedList queue; // most recently used node is at back of queue

    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(hashMap.find(key) == hashMap.end()) return -1;

        Node* node = hashMap[key];
        queue.moveToBack(node);
        return node->val;
    }
    
    void put(int key, int value) {
        //updating value
        if (hashMap.find(key) != hashMap.end()) {
            Node* node = hashMap[key];
            node->val = value;
            queue.moveToBack(node);
            return ;
        }

        Node* node = new Node(key, value);
        //resizing queue for adding new element
        if(hashMap.size() >= capacity) { //capacity > 0
            hashMap.erase(queue.front->key); //remove from hashmap
            queue.front = queue.front->next; //remove from queue
        }
        queue.addToBack(node);

        if(queue.back == nullptr) queue.back = queue.front;
        hashMap[key] = node;
    }
};

int main() {
    LRUCache lRUCache = LRUCache(2);
    //[2],[2,1],[1,1],[2,3],[4,1],[1],[2]
    lRUCache.put(2,1);
    lRUCache.put(1,1);
    lRUCache.put(2,3);
    lRUCache.put(4,1);
    //lRUCache.queue.print(true);
    lRUCache.get(1);
    cout<<lRUCache.get(2);
    return 0;
}

