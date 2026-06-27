class Solution {
public:
    // Hàm phụ để kiểm tra một đoạn chuỗi có đối xứng hay không
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // Khi gặp lỗi, thử 2 phương án: 
                // Xóa bên trái (nhảy qua left) HOẶC Xóa bên phải (nhảy qua right)
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        
        return true; // Chuỗi đã đối xứng sẵn (không cần xóa hoặc xóa đại 1 cái vẫn đúng)
    }
};
