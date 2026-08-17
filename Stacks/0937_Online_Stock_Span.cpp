// Problem   : 937. Online Stock Span
// Difficulty: Medium
// Tags      : Stack, Design, Monotonic Stack, Data Stream
// URL       : https://leetcode.com/problems/online-stock-span/
// Language  : Cpp
// Date      : 2026-08-17
//

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() { 
    }
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first<=price){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */