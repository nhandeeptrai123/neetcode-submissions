class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == t) {
            return true;
        }  
        map<char,int> mp;
        for(auto c : s) {
            mp[c]++;
        }
        for (auto c : t) {
            mp[c]--;
        }
        for (auto c : mp) {
            if (c.second != 0) return false;
        }
        return true;
    }
};
