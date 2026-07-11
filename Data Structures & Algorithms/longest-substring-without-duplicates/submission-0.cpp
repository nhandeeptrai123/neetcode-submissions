class Solution {
public:
       int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0;
        unordered_set <char> st;
        int n = s.size();
        while (r < n) {
            char c = s[r];
            if (st.find(c) != st.end()) {
                st.erase(s[l]);
                l++;
            }
            else {
                //nếu chưa có thì di chuyển r sang phải
                st.insert(s[r]);
                ans = max(ans, r - l + 1);
                r++;
            }
        }
        return ans;
    }
};
