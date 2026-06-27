class Solution {
public:
string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
    string res = "";
    if (strs.size() == 1) {
        return res = strs[0];
    }
    while (i < strs[0].size()) {
        char curr = strs[0][i]; //lay ky tu dau tien cua chuoi dau tien 
        bool avail = false; 
        for (int j = 1; j < strs.size(); j++) {
            if (strs[j][i] != curr) {
                avail = false; //Nếu ký tự của các chuỗi sau chuỗi đầu tiên khác thì sẽ thoát vòng lặp
                break;
            }
            else {
                avail = true;
            }
        }
        if (!avail) {
            return res;
        }
        else
        res += curr; //Thêm ký tự vào chuỗi kết quả 
        i++; //Dịch qua ký tự kế tiếp của chữ cái đầu tiên
    }
    return res;
    }
};