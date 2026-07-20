class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <long long> st;
        for (const string& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                st.push(stoll(token));
            }
            else {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();

                switch (token[0]) {
                    case '+': st.push(a + b); break;
                    case '-': st.push(a - b); break;
                    case '*': st.push(a * b); break;
                    case '/': st.push(a / b); break;
                }
            }
        }
        return st.top();
    }
};
