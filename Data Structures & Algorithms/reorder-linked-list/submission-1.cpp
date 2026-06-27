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
    ListNode* fast = head; 
    ListNode* slow = head;
    while (fast != nullptr && fast -> next != nullptr) {
        fast = fast -> next -> next;
        slow = slow -> next;
        //Di chuyen con tro fast toi cuoi hang thi con tro slow se o giua dslk
    }
    // cout << slow -> val << endl; //3
    // cout << slow -> next -> val; //4
    //B2: dao nguoc chuoi tu slow 
    ListNode* prevN = nullptr; 
    ListNode* currN = slow -> next; //Tao ra 2 doan 
    slow -> next = nullptr; //Cat doan giua de tach roi code    
    while (currN != nullptr) {
        if (!head || !head->next) return;
        // if (currN -> next == nullptr) break;
        ListNode* newN = currN -> next; //Luu tru tam dia chi phia sau cua currN
        currN -> next = prevN; //Tro nguoc ve prevN
        prevN = currN; //Di chuyen prevN len thanh currN 
        currN = newN;
    }
    //B3: Tron 2 danh sach lai voi nhau 
    ListNode* first = head; 
    ListNode* second = prevN; 
    //Tao 2 nua danh sach de chua
    while (second != nullptr) {
        ListNode* tmp1 = first -> next;
        ListNode* tmp2 = second -> next;
        first -> next = second; 
        second -> next = tmp1;
        first = tmp1; 
        second = tmp2;
    }
    }
};
