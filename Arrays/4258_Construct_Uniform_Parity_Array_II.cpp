// Problem   : 4258. Construct Uniform Parity Array II
// Difficulty: Medium
// Tags      : Array, Math
// URL       : https://leetcode.com/problems/construct-uniform-parity-array-ii/
// Language  : Cpp
// Date      : 2026-09-03
//

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int evenMin = INT_MAX;
        int evenCnt = 0;
        int oddMin = INT_MAX;
        int oddCnt = 0;
        int n = nums1.size();
        for(auto it: nums1){
            if(it%2==0){
                evenMin = min(it,evenMin);
                evenCnt++;
            }
            else{
                oddMin = min(it,oddMin);
                oddCnt++;
            }
        }
        if(evenCnt==n || oddCnt==n){
            return true;
        }
        bool isOdd = true;
        bool isEven = true;
        for(auto it: nums1){
            if(it%2==0){
                if(it-oddMin>=1){
                    continue;
                }
                isOdd = false;
                break;
            }
        }
        for(auto it: nums1){
            if(it%2==1){
                if(it-oddMin>=1){
                    continue;
                }
                isEven = false;
                break;
            }
        }
        return isOdd || isEven;
    }
};