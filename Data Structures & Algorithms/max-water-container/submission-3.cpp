class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n - 1;
        int max_area = 0;
        while (l < r) {
            int hl = heights[l];
            int rl = heights[r];
            int area = (r - l) * min(hl,rl);
            max_area = max(max_area, area);
            if (hl < rl) {
                while (l < r && hl >= heights[l]) l++;
            }
            else {
                while (l < r && rl >= heights[r]) r--;
            }
        }
        return max_area;
    }
};
