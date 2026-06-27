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
 ListNode* reverseList(ListNode* head) {
    vector <int> tmp; 
    ListNode* curr = head; 
    ListNode* res = new ListNode();
    //Day du lieu tu dau den cuoi dslk vao vector
    while (curr != nullptr) {
        tmp.push_back(curr -> val);
        curr = curr -> next; 
    }
    ListNode* curr2 = res; 
    //Duyet vector tu cuoi de dua vao danh sach moi
    for (int i = tmp.size() - 1; i >= 0; i--) {
        int x = i; 
        ListNode* newNode = new ListNode(tmp[i]);
        curr2 -> next = newNode;
        curr2 = curr2 -> next; 
    }
    return res -> next;
} 
};
