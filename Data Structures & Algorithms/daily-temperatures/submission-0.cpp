class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> res(n);
        if (n <= 0) return {};
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (temperatures[j] <= temperatures[i]) {
                    res[i] = 0;
                }
                else {
                    int gap = j - i; 
                    res[i] = gap;
                    break;
                }
            }
        }
        return res;
    }
};
