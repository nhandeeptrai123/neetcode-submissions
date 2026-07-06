class Solution {
public:
   int maxProfit(vector<int>& prices) {
        int buyday = 0, sellday = buyday + 1;
        int profit = 0;

        int n = prices.size();
        while (buyday < sellday && sellday < n) {
            int curr = prices[sellday] - prices[buyday];
            if (curr > profit) {
                //trường hợp lợi nhuận hiện tại lớn hơn quá khứ thì cập nhật lại
                //sau đó tính thử xem các ngày sau còn ngày nào bán cao hơn không
                profit = curr;
                sellday++;
            }
            else if (curr < 0) {
                //nếu như lợi nhuận hiện tại âm thì ta sẽ mua vào ngày bán và bán vào ngày khác
                buyday = sellday;
                sellday++;
            }
            else 
            //nếu không có gì thì dò đến hết xem 
            sellday++;
        }
        return profit;
    }
};
