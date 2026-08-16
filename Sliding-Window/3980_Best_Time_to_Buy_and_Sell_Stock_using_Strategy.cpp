// Problem   : 3980. Best Time to Buy and Sell Stock using Strategy
// Difficulty: Medium
// Tags      : Array, Sliding Window, Prefix Sum
// URL       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        ll actualProfit = 0;
        vector<int> profit(n);
        for(int i=0;i<n;i++){
            profit[i] = (ll)strategy[i] * prices[i];
            actualProfit += profit[i];
        }
        ll org_windowProfit = 0;
        ll mod_windowProfit = 0;
        ll maxGain = 0;
        int i = 0;
        int j = 0;
        while(j<n){
            org_windowProfit += profit[j];
            if(j-i+1>k/2){
                mod_windowProfit += prices[j];
            }
            if(j-i+1>k){
                org_windowProfit -= profit[i];
                mod_windowProfit -= prices[i+k/2];
                i++;
            }
            if(j-i+1==k){
                maxGain = max(maxGain, mod_windowProfit-org_windowProfit);
            }
            j++;
        }
        return actualProfit + maxGain;
    }
};