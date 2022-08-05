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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;

        while(list1 && list2) {
            if(list1->val > list2->val) swap(list1,list2); // ensure list1 value is smaller than list2
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;
        }

        tail->next = (list1) ? list1 : list2;

        return dummy->next;
    }
};

int main() {
    Solution s;
    ListNode* list1 = new ListNode({1,2,4,5,7});
    ListNode* list2 = new ListNode({1,3,3,6});
    // list1->print();
    // list2->print();
    s.mergeTwoLists(list1,list2)->print();
    return 0;
}

