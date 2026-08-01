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
    bool sameTree(TreeNode* p, TreeNode* q) {
        //hàm này dùng để kiểm tra từ cây p xuống dưới có trùng với cây q không
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr || q == nullptr) return false;

        if (p -> val != q -> val) return false;

        return sameTree(p -> left, q -> left) && sameTree(p -> right, q -> right);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        //base case: nếu đã duyệt hết cây rồi mà vẫn không tìm thấy -> return false; 

        if (sameTree(root, subRoot)) return true;
        //trường hợp 1: cây root chính là subroot luôn

        //trường hợp 2 & 3: 1 trong 2 cây con của root là subtree
        //gọi đệ quy xuống dưới để kiểm tra tiếp, nếu đúng thì nó sẽ nhảy vào trường hợp 1


        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot); 
            //đi kiểm tra cây con bên trái và phải của root để xem có xuất hiện subtree hay không
        
    }
};
