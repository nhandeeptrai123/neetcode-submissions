class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> st;

        for (int i = 0; i < operations.size(); i++) {
            string c = operations[i];
            if (c == "+") {
                int top1 = st.top();
                int sum = top1;
                st.pop();
                int top2 = st.top();
                sum += top2;
                st.push(top1);
                st.push(sum);
            }
            else if (c == "D") {
                int curr = st.top();
                st.push(curr * 2);
            }
            else if (c == "C") {
                st.pop();
            }
            else {
                st.push(stoi(c));
            }
        }
        int record =  0;
        while (!st.empty()) {
            record += st.top();
            st.pop();
        }
        return record;
    }
};