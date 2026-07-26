class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector <int> answer = nums; 
        for (int c : nums) {
            answer.push_back(c);
        }
        return answer;
    }
};