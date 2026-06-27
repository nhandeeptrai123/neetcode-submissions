class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
    while (columnNumber > 0) {
        columnNumber--; // Dịch chuyển để khớp với bảng chữ cái 0-25
        
        char c = (columnNumber % 26) + 'A';
        result = c + result; // Thêm vào bên trái chuỗi
        
        columnNumber /= 26;
    }
    return result;
    }
};