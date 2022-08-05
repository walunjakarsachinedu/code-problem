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
    void reorderList(ListNode* head) {
        ListNode *sp = head, *fp = head->next; //sp: slow pointer, fp: fast pointer
        while(fp && fp->next) sp = sp->next, fp= fp->next->next;

        ListNode *list = head;
        ListNode *rlist = reverseList(sp->next);
        sp->next = nullptr;

        while(rlist && list) {
            ListNode *lnext = list->next, *rlnext = rlist->next;
            list->next = rlist;
            rlist->next = lnext;
            list = lnext;
            rlist = rlnext;
        }
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while(head) {
            ListNode* headNext = head->next;
            head->next = prev;
            prev = head;
            if(headNext == nullptr) break;
            head = headNext;
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode* list1 = new ListNode({1,2,4,5,7,8});
    s.reorderList(list1);
    return 0;
}

