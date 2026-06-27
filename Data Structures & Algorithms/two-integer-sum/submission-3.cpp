class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = -99999999;
        int i = 0;
        vector <int> res; 
        while (sum != target) {
            sum = nums[i]; 
            for (int j = i + 1; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
                else {
                    sum = nums[i];
                }
            }
            i++;
        }
        return res;
        }
};
