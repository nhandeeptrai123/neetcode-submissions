class Solution {
public:
string countingSort(string s) {
    int count[26] = {0}; 
    for (char c : s) {
        count[c - 'a']++; //Đếm số lần xuất hiện của từng chữ cái 
    }
    string res = "";
    for (int i = 0; i < 26; i++) {
        res += string(count[i], i + 'a');
    }
    return res;
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <string, vector<string>> mp; //key là chuỗi đã sắp xếp, value là chuỗi chứa các chữ cái đó
    for (auto s : strs) {
        string key = countingSort(s); //Sắp xếp lại các chữ cái trong chuỗi
        mp[key].push_back(s); 
    }   
    vector<vector<string>> res;   
        for (auto const& [key,value] : mp) {
            res.push_back(value); //Đẩy vào res là các vector chứa trong từng key
        }
        return res;
    }
};
