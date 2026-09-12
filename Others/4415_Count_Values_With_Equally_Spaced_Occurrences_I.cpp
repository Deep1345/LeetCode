// Problem   : 4415. Count Values With Equally Spaced Occurrences I
// Difficulty: Easy
// Tags      : N/A
// URL       : https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-i/
// Language  : Cpp
// Date      : 2026-09-12
//

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101,0);
        for(auto it: nums){
            freq[it]++;
        }
        int ans = 0;
        for(int i=0;i<101;i++){
            if(freq[i]==3){
                int prev_ind = -1;
                int prev_diff = -1;
                bool flag = true;
                for(int j=0;j<n;j++){
                    if(flag==false){
                        continue;
                    }
                    if(nums[j]==i){
                        if(prev_ind!=-1){
                            int diff = j - prev_ind;
                            if(prev_diff!=-1){
                                if(diff!=prev_diff){
                                    flag = false;
                                }
                                else{
                                    prev_ind = j;
                                    continue;
                                }
                            }
                            else{
                                prev_diff = diff;
                                prev_ind = j;
                                continue;
                            }
                        }
                        else{
                            prev_ind = j;
                            continue;
                        }
                    }
                    else{
                        continue;
                    }
                }
                if(flag==true){
                    ans++;
                }
            }
            else{
                continue;
            }
        }
        return ans;
    }
};