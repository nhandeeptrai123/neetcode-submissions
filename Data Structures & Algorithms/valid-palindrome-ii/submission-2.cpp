class Solution {
public:
    // Hàm phụ để kiểm tra một đoạn chuỗi có đối xứng hay không
    bool isPalindrome(string str, int left, int right) {
        while (left <= right) {
            if (str[left] != str[right]) {
                return false;
            }
             left++; 
             right--;
        }
        return true; 
    }
    bool validPalindrome(string str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return (isPalindrome(str, left + 1, right) || isPalindrome(str, left, right - 1));
            }
            left++;
            right--; 
            //thu hẹp khoảng cách cho đến khi tìm được cặp không bằng nhau
        }
        return true;
    }
};
