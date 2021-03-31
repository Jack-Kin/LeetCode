#include <iostream>
using namespace std;

struct ListNode {
      int val;ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode* next = reverseList(head->next);
        // 这里是head.next.next 不是next.next ！！
        head->next->next = head;
        head->next = nullptr;
        return next;
    }
};

int main() {
    ListNode l = ListNode(1);
    l.next = new ListNode(2);
    l.next->next = new ListNode(3);
    l.next->next->next = new ListNode(4);
    l.next->next->next->next = new ListNode(5);
    l.next->next->next->next->next = new ListNode(6);

    Solution solution;
    ListNode *l2 = solution.reverseList(&l);
    ListNode *it = l2;
    while (it) {
        cout << it->val << " ";
        it = it->next;
    }
    return 0;
}