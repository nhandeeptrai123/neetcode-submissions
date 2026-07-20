class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        for (int curr : asteroids) {
            bool destroyed = false; //dùng để đánh dấu xem có nổ hay không

            //va chạm chỉ xảy ra khi có viên dương ở đỉnh và hiện tại là viên âm 

            while (!st.empty() && st.top() > 0 && curr < 0) {
                int top_size = st.top();
                int curr_size = abs(curr); 
                if (top_size < curr_size) {
                    //nếu viên dương nhỏ hơn viên âm hiện tại thì nổ và cho viên âm vào
                    st.pop();
                    
                    
                }
                else if (top_size == curr_size) {
                    st.pop(); 
                    destroyed = true;
                    break; //dừng va chạm
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(curr);
            }
        }
        vector <int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};