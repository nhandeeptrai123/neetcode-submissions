class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for (auto i : nums) {
            mp[i]++;
        }
        for (auto &m : mp) {
            minHeap.push({m.second, m.first});
            //Push tần số trước, số sau 
            if (minHeap.size() > k) {
                minHeap.pop();
            }
            //Nếu kích thước heap lớn hơn k thì loại bỏ 
        }
        vector <int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};
