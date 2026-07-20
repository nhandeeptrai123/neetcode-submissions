class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            string curr = tokens[i];
            int top1 = 0, top2 = 0;
            if (curr == "+") {
                if (!st.empty())
                top1 = st.top(); 
                st.pop();
                if (!st.empty())
                top2 = st.top();
                st.pop();
                st.push(top1 + top2);
            }
            else if (curr == "-") {
                if (!st.empty())
                top1 = st.top(); 
                st.pop();
                if (!st.empty())
                top2 = st.top();
                st.pop();
                st.push(top2 - top1);
            }
            else if (curr == "*") {
                if (!st.empty())
                top1 = st.top(); 
                st.pop();
                if (!st.empty())
                top2 = st.top();
                st.pop();
                st.push(top1 * top2);
            }
            else if (curr == "/") {
                if (!st.empty())
                top1 = st.top(); 
                st.pop();
                if (!st.empty())
                top2 = st.top();
                st.pop();
                st.push(top2 / top1);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
