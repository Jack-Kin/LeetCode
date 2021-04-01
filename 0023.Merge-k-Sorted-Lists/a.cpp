#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// recursion
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, (int)lists.size()-1);
    }

    ListNode *merge(vector<ListNode*> &lists, int l, int r) {
        if (l == r) return lists[r];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

};

// priority queue
class Solution2 {
public:
    struct compare {
        bool operator()(const ListNode *l, const ListNode *r) {
            return l->val > r->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare > pq;
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        if (pq.empty()) return nullptr;

        ListNode *result = pq.top();
        pq.pop();
        if (result->next) {
            pq.push(result->next);
        }
        ListNode *it = result;
        while (!pq.empty()){
            it->next = pq.top();
            pq.pop();
            it = it->next;
            if (it->next) pq.push(it->next);
        }
        return result;
    }
};