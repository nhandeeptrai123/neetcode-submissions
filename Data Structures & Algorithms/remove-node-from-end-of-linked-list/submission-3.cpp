/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* L = dummy;
    ListNode* R = dummy;  
    while (n-- && R -> next != nullptr) {
        R = R -> next; 
    }
    while (R -> next != nullptr) {
        L = L -> next; 
        R = R -> next; 
    }
    cout << L -> val << endl; 
    cout << R -> val << endl; 
    L -> next = L -> next -> next; 
    return dummy -> next; 
    }
};
