/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        while (curr != nullptr) {
            //tạo danh sách chứa địa chỉ của node mới được sao chép
            mp[curr] = new Node(curr -> val);
            curr = curr -> next;
        }
        curr = head;
        while (curr != nullptr) {
            mp[curr] -> next = mp[curr -> next]; 
            //mp[curr] = A'
            //mp[curr -> next] = A' -> next
            //curr -> next = B;
            //mp[curr -> next] = B'
            // => A' -> B'
            mp[curr] -> random = mp[curr -> random];
            curr = curr -> next;
        }

        return mp[head];
        //Trả về vị trí A'
        //mp[head] = mp[A] = A'


    }
};
