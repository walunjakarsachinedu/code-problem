#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     ListNode(vector<int> values) {
        vector<ListNode*> nodes(values.size());
        for(int i=0;i<values.size();i++) {
            nodes[i] = new ListNode(values[i]);
            if(i>0) nodes[i-1]->next = nodes[i];
        }
        val = nodes[0]->val;
        next = nodes[0]->next;
     }
     void print() {
        ListNode *node = this;
        while(node) cout<<node->val<<" ",node=node->next;
        cout<<endl;
     }

     void reversePrint() {
        stack<int> st;
        ListNode* node = this;
        while(node) st.push(node->val),node=node->next;
        while(!st.empty()) cout<<st.top(),st.pop();
        cout<<endl;
     }
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *res, *prev=nullptr;
        ListNode *p1=l1, *p2=l2;
        ListNode *head;
        while(p1 || p2) {
            int sum = 0;
            if(p1) sum+=p1->val;
            if(p2) sum+=p2->val;

            sum += carry;
            res = new ListNode(sum%10);
            carry=sum/10;
            //setting links
            if(prev) prev->next = res;
            else head = res;
            prev = res;
            //updating pointer
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
            // optimization
            if(carry == 0 && (p1==nullptr || p2==nullptr)) {
                if(p1) res->next = p1;
                if(p2) res->next = p2;
                break;
            }
        }
        if(carry) {
            res = new ListNode(carry);
            prev->next = res;
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode({2,4,6,1,2,3});
    ListNode* head1 = new ListNode({2,4,6});
    s.addTwoNumbers(head,head1)->reversePrint();
    cout<<321642+642<<endl;
    return 0;
}

