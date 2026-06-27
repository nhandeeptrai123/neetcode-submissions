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
        if (root == nullptr) return 0; 
        
        int LeftHight = checkHeight(root -> left); //Đi xuống kiểm tra cánh trái 
        if (LeftHight == -1) return -1; //Thằng con báo hỏng thì mình cũng hỏng

        int RightHight = checkHeight(root -> right); 
        if (RightHight == -1) return -1;

        int gap = abs(LeftHight - RightHight); 
        if (gap > 1) return -1;

        return max(LeftHight, RightHight) + 1;
    }  
    bool isBalanced(TreeNode* root) {
        return(checkHeight(root) != -1);
    }
};
