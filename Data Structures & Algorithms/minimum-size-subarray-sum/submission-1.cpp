class Solution {
public:
        int minSubArrayLen(int target, vector<int>& nums) {
        int sz = nums.size(); 
        if (sz <= 0) return 0;

        int l = 0; 
        int sum = 0;
        int min_length = INT_MAX;
        for(int r = 0; r < sz; r++) {
            
                sum += nums[r];
            
            //sau khi vượt qua target 1 khoảng lố rồi thì xem thu hẹp được khoảng cách không
                while (sum >= target) {
                    min_length = min(r - l + 1, min_length);
                    sum -= nums[l];
                    l++;
                }
            }

        return (min_length == INT_MAX) ? 0 : min_length;
    }
};