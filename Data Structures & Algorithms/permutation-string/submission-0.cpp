class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) return false; 
        vector <int> counts1(26,0);
        vector <int> counts2(26,0);
        for (int i = 0; i < n1; i++) {
            char c = s1[i];
            counts1[c - 'a']++; //lưu tần suất xuất hiện của từng ký tự
        }

        //duyệt qua cửa sổ đầu tiên mảng s2
        for (int i = 0; i < n1; i++) {
            char c = s2[i];
            counts2[c - 'a']++;
        }
        if (counts1 == counts2) return true;

        //duyệt từ vị trí cửa sổ tiếp theo

        for (int i = n1; i < n2; i++) {
            counts2[s2[i - n1] - 'a']--;
            counts2[s2[i] - 'a']++;

            if (counts1 == counts2) return true;
        }
        return false;
    }
};
