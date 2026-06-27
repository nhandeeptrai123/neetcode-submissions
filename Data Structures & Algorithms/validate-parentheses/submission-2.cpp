class Solution {
public:
    bool isValid(string s) {
        int sz = s.size();
        if (sz == 0) return true;
        stack <char> st;
        for (int i = 0; i < sz; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                //Truong hop khong phai cac ky tu thi pop ra de so sanh
                if (st.empty()) return false;
                char c = st.top();
                st.pop();
                if (c == '(' && s[i] != ')' ||
                    c == '[' && s[i] != ']' ||
                    c == '{' && s[i] != '}') {
                   return false;
                }
            }
        }
        if (st.empty()) return true;
        return false;
    }
};
