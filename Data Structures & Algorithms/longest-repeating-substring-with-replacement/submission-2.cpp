class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = l, n = s.size(), max_len = 0; 
        vector <int> counts(26,0);
        int max_count = 0;
        while (r < n) {
            counts[s[r] - 'A']++;
            max_count = max(counts[s[r] - 'A'], max_count);
            //tăng số lần xuất hiện của từng ký tự lên

            int length = r - l + 1;

            int replace = length - max_count;

            if (replace <= k) {
                max_len = length;
            }
            else {
                counts[s[l] - 'A']--;
                //1 ký tự vừa trượt ra khỏi cửa sổ nên loại bỏ nó
                l++; //thu hẹp cửa số về bên phải
            }
            r++;
        }
        return max_len;
    }
};
