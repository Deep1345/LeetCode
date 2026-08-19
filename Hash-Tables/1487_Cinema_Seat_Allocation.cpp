// Problem   : 1487. Cinema Seat Allocation
// Difficulty: Medium
// Tags      : Array, Hash Table, Greedy, Bit Manipulation
// URL       : https://leetcode.com/problems/cinema-seat-allocation/
// Language  : Cpp
// Date      : 2026-08-19
//

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for(auto &x : reservedSeats) {
            mp[x[0]].push_back(x[1]);
        }
        int ans = 0;
        ans = (n-mp.size())*2;
        for(auto &[row, seats] : mp) {
            bool left = true;
            bool middle = true;
            bool right = true;
            for(int seat : seats) {
                if(seat >= 2 && seat <= 5){
                    left = false;
                }
                if(seat >= 4 && seat <= 7){
                    middle = false;
                }
                if(seat >= 6 && seat <= 9){
                    right = false;
                }
            }
            if(left==true && right==true){
                ans += 2;
            }
            else if(left==true || middle==true || right==true){
                ans++;
            }
        }
        return ans;
    }
};