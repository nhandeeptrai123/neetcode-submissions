class Solution {
public:
    bool canShip(vector<int>& weights, int cap, int days) {
        int totalDays = 1;
        int currentWeight = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (currentWeight + weights[i] > cap) {
                totalDays++;
                currentWeight = weights[i];
            }
            else {
                currentWeight += weights[i];
            }
        }
        return totalDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int max_weight = 0;
        int sum_weight = 0;
        for (auto w : weights) {
            max_weight = max(max_weight, w);
            sum_weight += w;
        }
        int l = max_weight;
        int r = sum_weight;
        int record = r;
        while (l <= r) {
            int cap = l + (r - l) / 2;

            if (canShip(weights, cap, days)) {
                record = cap;
                r = cap - 1;
            }
            else {
                //nếu không chở vừa thì tăng lên
                l = cap + 1;
            }
        }
    return record;
    }
};