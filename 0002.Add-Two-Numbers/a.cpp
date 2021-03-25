#include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode sumHead(0);
        ListNode *p = &sumHead;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10;
            p->next = new ListNode(sum%10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return sumHead.next;
    }
};


int main(){
//    ListNode l0(0);
//    ListNode *p = &l0;
//    ListNode l2(2,p);
//    ListNode l3(3,&l2);
//    ListNode l4(4,&l3);
//
//    ListNode *it = &l4;
//    while (it) {
//        cout << it->val << endl;
//        it = it->next;
//    }
    cout << (int)(4+8)/10<< endl;
    cout << (int)(4+8)%10<< endl;

    return 0;
}