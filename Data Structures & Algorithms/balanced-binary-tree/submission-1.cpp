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
    int checkHeight(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = checkHeight(root -> left);
        if (leftHeight == -1) return -1;
        //nếu nhánh dưới đã mất cân bằng, thì trả về nút cha cũng báo mất cân bằng

        int rightHeight = checkHeight(root -> right);
        if (rightHeight == -1) return -1;

        int gap = abs(leftHeight - rightHeight);
        if (gap <= 1) {
            //Vẫn cân bằng, trả về chiều cao của nút hiện tại để tính lên 
            return 1 + max(leftHeight, rightHeight);
        }
        else {
            return -1;
        }
        
    }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
