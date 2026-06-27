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
    ListNode* prevN = nullptr; //Dung de luu dslk nguoc 
    ListNode* currN = head; //Tro toi vi tri hien tai trong ds
    while (currN != nullptr) {
        ListNode* nextN = currN -> next; //Tao ra node nextN de chua tam dia chi tiep theo cua currN
        currN -> next = prevN; //tro nguoc ve node prevN
        prevN = currN; //Di chuyen prev ve sau tro thanh node curr
        currN = nextN;
    }
    return prevN;
}
};
