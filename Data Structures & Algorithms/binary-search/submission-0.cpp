class Solution {
private:
int binarySearch(vector<int> &nums, int left, int right, int target) {
    if (left > right) return -1;
    int middle = (right + left) / 2;
    if (nums[middle] < target) {
        return binarySearch(nums, middle + 1, right, target);
    }
    else if (nums[middle] > target) {
        return binarySearch(nums, left, middle - 1, target);
    }
    else {
        return middle;
    }
}
public:

    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int pos = binarySearch(nums, left, right, target);
        return pos;
    }
};
