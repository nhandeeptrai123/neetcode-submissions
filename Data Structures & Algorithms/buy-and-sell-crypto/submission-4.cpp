class Solution {
public:
   int maxProfit(vector<int>& prices) {
        int buyday = 0, sellday = buyday + 1;
        int profit = 0;

        int n = prices.size();
        while (buyday < sellday && sellday < n) {
            int curr = prices[sellday] - prices[buyday];
            if (curr > 0) {
                //nếu giá ngày bán lớn hơn giá ngày mua thì ta tiến hành so sánh xem nó có lớn hơn lợi nhuận hiện tại không
            
                if (curr > profit) {
                profit = curr;
                }
            }
            else {
                //nếu như lợi nhuận hiện tại âm thì ta sẽ mua vào ngày bán và bán vào ngày khác
                buyday = sellday;
            }
            //nếu không có gì thì dò đến hết xem 
            sellday++;
        }
        return profit;
    }
};
