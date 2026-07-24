class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr;
        int m = matrix.size(); //số hàng
        int n = matrix[0].size(); //số cột
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr.push_back(matrix[i][j]);
            }
        }

        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (arr[m] == target) {
                return true;
            }
            else if (arr[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return false;
    }
};
