class Solution {
public:

    bool canEatAll(vector<int>& piles, int h, int k) {
        //dùng để tìm số k phù hợp 
        long long totalHours = 0;

        for (int i = 0; i < piles.size(); i++) {
            long long time_to_eat = (piles[i] + k - 1) / k;

            totalHours += time_to_eat;

            if (totalHours > h) return false;
        }
        return totalHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int max_pile = 0;
        for (auto &p : piles) {
            max_pile = max(p, max_pile);
        }
        int r = max_pile; 
        int record = r;
        while (l <= r) {
            int k = l + (r - l) / 2;

            if (canEatAll(piles, h, k)) {
                record = k;
                r = k - 1;
                //nếu ăn hết thì lưu kỷ lục lại và thử tìm xem bên trái có ăn chậm hơn được khôgn
            }
            else {
                //nếu ăn không kịp thì tăng tốc độ ăn lên
                l = k + 1;
            }
        }
    return record;
    }
};
