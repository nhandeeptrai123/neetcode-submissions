class Solution {
public:

    bool compareGap(int a, int b, int x) {
        if (abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b)) return true;
        return false; 
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l < r && r - l + 1 != k) {
            if (compareGap(arr[l], arr[r], x)) {
                r--; //nếu khoảng cách từ l tới x < r tới x 
            }
            else {
                l++;
            }
        }
        vector <int> res;
        for (int i = l; i < r + 1; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};