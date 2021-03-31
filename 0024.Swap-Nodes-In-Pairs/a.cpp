#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 很傻的循环方法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *it = head;
        if (head) {
            if (head->next) {
                head = head->next;
            }
        }
        ListNode *first = nullptr;
        ListNode *second = nullptr;
        ListNode *third = nullptr;
        ListNode *fourth = nullptr;
        while (it) {
            ListNode *fifth = nullptr;
            if (it->next) {
                first = it;
                second = it->next;
                // swap 1st and 2nd
                first->next = second->next;
                second->next = first;
                if (third) {
                    third->next = second;
                }
                it = first;
                if (it->next) {
                    third = it->next;
                    it = third;
                    if (it->next) {
                        fourth = it->next;
                        fifth = fourth->next;
                        // swap 3rd and 4th
                        first->next = fourth;
                        fourth->next = third;
                    }
                    third->next = fifth;
                }
            }
            it = fifth;
        }
        return head;
    }
};
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode *second = head->next;
        ListNode *it = swapPairs(head->next->next);
        second->next = head;
        head->next = it;
        return second;
    }
};

int main(){
    ListNode l = ListNode(1);
    l.next = new ListNode(2);
    l.next->next = new ListNode(3);
    l.next->next->next = new ListNode(4);
    l.next->next->next->next = new ListNode(5);
    l.next->next->next->next->next = new ListNode(6);

    Solution solution;
    ListNode *l2 = solution.swapPairs(&l);
    ListNode *it = l2;
    while (it) {
        cout << it->val << " ";
        it = it->next;
    }
    return 0;

}