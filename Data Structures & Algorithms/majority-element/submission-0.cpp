class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> mp; 
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int max = 0;
        int res = 0;
        for (auto c : mp) {
            if (c.second > max) {
                max = c.second;
                res = c.first;
            }
        }
        return res;
    }
};