class Solution {
public:
    void merge(vector<int> &nums, int l, int r, int m) {
        //Trộn 2 dãy con [l,m] và [m+1, r]
         
        vector <int> leftSide(nums.begin() + l, nums.begin() + m + 1); 
        vector <int> rightSide(nums.begin() + m + 1, nums.begin() + r + 1);
        int i = 0, j = 0, k = l; 
        //i lưu vị trí của leftSide, j lưu vị trí của rightSide, k lưu vị trí của mảng gộp
        while (i < leftSide.size() && j < rightSide.size()) {
            if (leftSide[i] < rightSide[j]) {
                nums[k++] = leftSide[i++];
            }
            else {
                nums[k++] = rightSide[j++];
            }
        }
        while (i < leftSide.size()) nums[k++] = leftSide[i++];
        while (j < rightSide.size()) nums[k++] = rightSide[j++]; 
        //Cộng phần dư 
}
void mergeSort(vector<int> &nums, int l, int r) {
    if (l >= r) {
        return;
    } 
    int m = (l + r) / 2;
    mergeSort(nums, l, m);
    mergeSort(nums, m + 1, r);
    merge(nums, l, r, m);
}
    vector<int> sortArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1; 
        mergeSort(nums, l, r);
        return nums;
    }
};