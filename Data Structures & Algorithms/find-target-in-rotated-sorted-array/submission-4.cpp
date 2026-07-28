class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {return m;}

            //tìm khoảng tăng dần 
            if (nums[l] <= nums[m]) {
                //trường hợp bên trái tăng dần
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                    //nếu target nằm trong khoảng xác định thì thu hẹp 
                }
                else {
                    //nếu không thì tìm nửa bên phải chưa được sắp xếp
                    l = m + 1;
                }
            }
            else {
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
                //trường hợp bên phải tăng dần
            }
        }
        return -1;
    }
};
