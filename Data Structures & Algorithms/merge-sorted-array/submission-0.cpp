class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i = m - 1;
        int j = n - 1; //trỏ vào vị trí cuối cùng của nums2
        int k = m + n - 1; 
        while (k && i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j]) {
                nums1[k--] = nums2[j];
                j--;
                for (auto c : nums1) {
                    cout << c << " ";
                }
                cout << endl;
            }
            else {
                nums1[k--] = nums1[i];
                i--;
                for (auto c : nums1) {
                cout << c << " ";
                }
                cout << endl;
            }
        }
        while (i >= 0) nums1[k--] = nums1[i--];
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};