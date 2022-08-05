#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     ListNode(vector<int> values) {
        val = values[0];
        ListNode* iter = nullptr;
        for(int i=1;i<values.size();i++) {
            if(iter == nullptr) {
                iter = new ListNode(values[i]);
                next = iter;
                continue;
            } 
            iter->next = new ListNode(values[i]);
            iter = iter->next;
        }
     }
     void print() {
        ListNode* list = next;
        cout<< val << " ";
        while (list != nullptr) {
            cout << list->val << " ";
            list = list->next;
        }
        cout << endl;
     }
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;

        while (p2 && n) --n, p2 = p2->next;
        if(p2 == nullptr)  return head = head->next;
        while (p2->next) p1 = p1->next, p2 = p2->next;

        if(p1->next) p1->next = p1->next->next;

        return head;
    }
};

int main() {
    Solution s;
    s.removeNthFromEnd(new ListNode({1,2,5,3}),3)->print();
    return 0;
}

