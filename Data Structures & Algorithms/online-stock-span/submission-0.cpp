class StockSpanner {
private: 
    stack <pair<int,int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            //chừng nào giá của ngày hôm nay lớn hơn giá của đỉnh thì cộng span
            span += st.top().second;
            st.pop();

        } 
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */