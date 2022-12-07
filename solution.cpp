#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    friend ostream& operator<<(ostream& cout, const ListNode* node) {
      while(node!=NULL) {
        cout << node->val << " ";
        node = node->next;
      }
      cout << "\b";
      return cout;
    }
};

// 328. Odd Even Linked List
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      ListNode *even, *odd, *iter, *even_head;
      even = odd = iter = even_head = NULL;
      iter = head;
      int i = 1;
      while(iter!=NULL) {
        if (i % 2 == 1) {
          if(odd) odd = odd->next = iter;
          else odd = iter;
        }
        else {
          if(even) even = even->next = iter;
          else even = even_head = iter;
        }
        iter = iter->next;
        ++i;
      }
      if(even) even->next = NULL;
      if(odd) odd->next = even_head;
      return head;
    }
};

int main() {
  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  head = Solution().oddEvenList(head);
  cout << "head: " << head << endl;
  return 0;
}