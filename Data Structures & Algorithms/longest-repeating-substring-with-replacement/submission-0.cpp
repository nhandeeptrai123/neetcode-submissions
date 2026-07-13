class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int max_len = 0;
        for (int i = 0; i < n; i++) {
        unordered_map <char, int> mp;
        int max_count = 0;
            for (int j = i;j < n; j++) {
                mp[s[j]]++; //Đếm số lần xuất hiện của các phần tử 

                max_count = max(max_count, mp[s[j]]);
                //Số lần xuất hiện nhiều nhất của 1 ký tự trong 1 dãy con

                //tính chiều dài dãy con hiện tại
                int curr_substr_length = j - i + 1;

                //số ký tự cần thay thế là bằng chiều dài của dãy con hiện tại trừ cho số ký tự xuất hiện nhiều nhất trong dãy con đó

                int replace_needed = curr_substr_length - max_count; 

                if (replace_needed <= k) {
                    //Nếu số lần thay thế là hợp lệ thì chấp nhận
                    max_len = max(max_len, curr_substr_length); 
                    //lưu chiều dài mảng con hiện tại thành dài nhất
                }
                else {break;} //nếu không thì break sang đoạn khác xét tiếp

            }
        }
                return max_len; 
    }
};
