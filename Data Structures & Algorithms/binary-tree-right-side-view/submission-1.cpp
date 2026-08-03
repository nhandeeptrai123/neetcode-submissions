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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        queue<TreeNode*> dq; 
        dq.push(root);

        while (!dq.empty()) {
            int level_size = dq.size();

            for (int i = 0; i < level_size; i++) {
                TreeNode* curr_node = dq.front();
                dq.pop();
                //lấy phần tử ra
                
                if (i == level_size - 1) {
                    //lấy phần tử cuối cùng cho vào result là node sẽ được nhìn thấy 
                    result.push_back(curr_node -> val);
                }
                if (curr_node -> left != nullptr) {
                    dq.push(curr_node -> left);
                }
                if (curr_node -> right != nullptr) {
                    dq.push(curr_node -> right);
                }
            }
        }
        return result;
    }
};
