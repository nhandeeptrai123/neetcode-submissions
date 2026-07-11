class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set <int> st;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            if (st.find(nums[i]) != st.end()) return true;
            st.insert(nums[i]);
            //thêm các phần tử của cửa sổ đầu tiên vào set để lưu sự tồn tại của nó
        }
        for (int i = k; i < n; i++) {
            if (st.find(nums[i]) != st.end()) {
                return true;
                //Nếu phần tử vừa được trượt vào bằng với phần tử đã nằm trong cửa sổ trước đó
                //và nằm trong set thì trả về true
            }
            else {
                st.erase(nums[i - k]);
                st.insert(nums[i]);
                //nếu chưa xuất hiện thì thêm vào set, sau đó di dời cửa sổ qua để tìm tiếp
            }
        }
        return false;
    }
};