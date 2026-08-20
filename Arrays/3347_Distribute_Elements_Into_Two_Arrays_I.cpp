// Problem   : 3347. Distribute Elements Into Two Arrays I
// Difficulty: Easy
// Tags      : Array, Simulation
// URL       : https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
// Language  : Cpp
// Date      : 2026-08-20
//

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        int n = nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(arr1.back()>arr2.back()){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        int m = arr2.size();
        for(int i=0;i<m;i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};