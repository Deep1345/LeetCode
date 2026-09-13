// Problem   : 940. Fruit Into Baskets
// Difficulty: Medium
// Tags      : Array, Hash Table, Sliding Window
// URL       : https://leetcode.com/problems/fruit-into-baskets/
// Language  : Cpp
// Date      : 2026-09-13
//

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        unordered_map<int,int> freq;
        int maxFruits = 0;
        for(int r=0;r<n;r++){
            freq[fruits[r]]++;
            if(freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0){
                    freq.erase(fruits[l]);
                }
                l++;
            }
            maxFruits = max(maxFruits,r-l+1);
        }
        return maxFruits;
    }
};