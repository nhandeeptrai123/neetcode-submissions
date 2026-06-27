class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
        vector<int> total(n, 1);
        total[0] = 1;
        for (int i = 1; i < n; i++) {
            total[i] = total[i - 1] * nums[i - 1];
        }
        vector<int> suf(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            total[i] = total[i] * suf[i];
        }
        return total;
    }
};
