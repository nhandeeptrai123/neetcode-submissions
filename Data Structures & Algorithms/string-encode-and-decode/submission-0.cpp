class Solution {
public:

    string encode(vector<string>& strs) {
        string encode_str = "";
        for (int i = 0; i < strs.size(); i++) {
            encode_str += to_string(strs[i].length()) + "#" + strs[i];
        }
        return encode_str;
    }

    vector<string> decode(string s) {
        int i = 0; 
        vector <string> decoded_list;
        while (i < s.length()) {
            int j = s.find("#", i);
            if (j == string::npos) {
                break; //nếu đã duyệt xong hết thì break ra 
            }
            int n = stoi(s.substr(i, j - i));
            decoded_list.push_back(s.substr(j + 1, n));
            i = j + n + 1;
        }
        return decoded_list;
    }
};
