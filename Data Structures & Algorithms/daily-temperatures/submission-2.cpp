class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack <int> st;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
