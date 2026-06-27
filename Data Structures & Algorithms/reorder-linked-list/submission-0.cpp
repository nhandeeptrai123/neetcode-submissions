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
    void reorderList(ListNode* head) {
        
    if (!head || !head->next) return;

    // 1. Tìm trung điểm
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Đảo ngược nửa sau (Bắt đầu từ slow->next)
    ListNode *prev = nullptr, *curr = slow->next;
    slow->next = nullptr; // Cắt đôi danh sách tại đây
    while (curr) {
        ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }

    // 3. Trộn đan xen hai danh sách (head và prev)
    ListNode *first = head, *second = prev;
    while (second) {
        ListNode *tmp1 = first->next;
        ListNode *tmp2 = second->next;

        first->next = second; // Nối trái sang phải
        second->next = tmp1;  // Nối phải về trái kế tiếp

        first = tmp1;
        second = tmp2;
    }
}
};
