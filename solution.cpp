#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p1=nullptr, *iter = head;
        while(iter!=nullptr) {
            ListNode* temp = iter->next;
            iter->next = p1;
            p1 = iter;
            if(temp==nullptr)  break;
            iter = temp;
        }
        return iter;
    }
};

int main() {

    return 0;
}

