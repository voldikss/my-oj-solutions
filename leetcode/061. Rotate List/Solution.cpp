//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {
  }
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head) return NULL;
    if (head->next == NULL) return head;
    if (k == 0) return head;
    int len = 0;
    int pos;
    ListNode *res = head;
    ListNode *end = head;
    while (end->next) {
      end = end->next;
      ++len;
    }
    ++len;

    if (k % len == 0)
      pos = 0;
    else
      pos = len - k % len;
    cout << "pos=" << pos << "len=" << len << endl;
    if (pos == 0) return head;

    int i = 0;
    while (i < pos - 1) {
      res = res->next;
      ++i;
    }
    ListNode *tmp = res;
    res = res->next;
    tmp->next = NULL;
    end->next = head;
    return res;
  }
};

int main() {
  // struct ListNode *l;
}
