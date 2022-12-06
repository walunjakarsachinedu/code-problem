#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 876. Middle of the Linked List
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
      ListNode *sp = head, *fp = head;
      while(fp!=NULL && fp->next!=NULL) {
        sp = sp->next;
        fp = fp->next->next;
      }
      return sp;
    }
};

int main() {
  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3)));
  ListNode* middleNode = Solution().middleNode(head);
  cout << "middle node: " << middleNode->val << endl;
  return 0;
}