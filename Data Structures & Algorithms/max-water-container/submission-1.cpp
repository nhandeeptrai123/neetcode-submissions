class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int max = 0;
        for (int l = 0; l < n - 1; l++) {
            for (int r = l + 1; r < n; r++) {
                int curr = (r - l) * min(heights[l], heights[r]);
                if (curr > max) {
                    max = curr;
                }
            }
        }
        return max;
    }
};
