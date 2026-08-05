/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isSame(vector<vector<int>>& grid, int r, int c, int length) {
        int firstVal = grid[r][c];
        //dùng để kiểm tra toàn bộ vùng này có đồng nhất giá trị hay không
        for (int i = r; i < r + length; i++) {
            for (int j = c; j < c + length; j++) {
                if (grid[i][j] != firstVal) {
                    return false;
                }
            }
        }
        return true;
    }

    Node* solve(vector<vector<int>>& grid, int r, int c, int length) {
        if (isSame(grid, r, c, length)) {
            return new Node(grid[r][c], 1);
            //nếu toàn bộ vùng này là đồng nhất thì đánh dấu isLeaf = 1
        }

        //trường hợp không phải thì cắt ma trận thành 4 phần bằng nhau
        int half = length / 2;

        Node* topLeft = solve(grid, r, c, half);
        Node* topRight = solve(grid, r, c + half, half);
        Node* bottomLeft = solve(grid, r + half, c, half);
        Node* bottomRight = solve(grid, r + half, c + half, half);
        //tạo nút hiện tại, val true/false đều được, còn isLeaf = false
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        //cho nút gốc ban đầu làm root
        return solve(grid, 0,0, n);
    }
};