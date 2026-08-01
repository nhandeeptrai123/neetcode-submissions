/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int depth(TreeNode* root, int &maxDiameter) {
        if (!root) return 0; //cây rỗng, đi xuống tận cùng thì chiều cao = 0


        int leftHeight = depth(root -> left, maxDiameter); 
        int rightHeight = depth(root -> right, maxDiameter);
        //tổng chiều cao của 1 node X = leftHeight + rightHeight;
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        //tại nút hiện tại, nếu ta uốn cong đường đi từ lá bên trái -> nút hiện tại -> lá bên phải, ta sẽ có 1 dường đi chữ U có độ dài bằng: leftDepth + rightDepth
        //Sau đó lấy độ dài này so với kỷ lục cũ lưu trong maxDiameter
        return 1 + max(leftHeight, rightHeight);
        //dòng này dùng để trả về cho nút cha biết: đi theo nhánh nào của nút cha thì sẽ dài hơn, ta chọn 1 trong 2 nhánh dài hơn bằng cách dùng hàm max, cộng thêm 1 là ra cạnh nối từ nút cha xuống nút hiện tại
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        depth(root, maxDiameter);
        return maxDiameter;
    }
};
