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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key < root -> val) {
            root -> left = 
            deleteNode(root -> left, key);
            return root; 
        }
        else if (key > root -> val) {
            root -> right = deleteNode(root -> right, key);
            return root;
        }
        else {
            if (root -> left != nullptr && root -> right != nullptr) {
                TreeNode* temp = root -> right;
                while (temp -> left != nullptr) {
                    temp = temp -> left;
                }
                root -> val = temp -> val;
                root -> right = deleteNode(root -> right, temp -> val);
                //xóa nút temp cũ 
                return root;
            }
            //trường hợp 1 con or nút lá
            else {
                TreeNode* child = (root -> left != nullptr) ? root -> left : root -> right;
                delete root;
                return child;
            }
        }
    }
};