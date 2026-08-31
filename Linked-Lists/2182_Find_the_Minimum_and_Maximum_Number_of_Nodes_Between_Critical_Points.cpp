// Problem   : 2182. Find the Minimum and Maximum Number of Nodes Between Critical Points
// Difficulty: Medium
// Tags      : Linked List
// URL       : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
// Language  : Cpp
// Date      : 2026-08-31
//

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
            return {-1,-1};
        }
        vector<int> indexes;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        while(curr->next!=nullptr){
            ListNode* next = curr->next;
            if((prev->val<curr->val && curr->val>next->val) || (prev->val>curr->val && curr->val<next->val)){
                indexes.push_back(index);
            }
            prev = curr;
            curr = next;
            index++;
        }
        if(indexes.size()<2){
            return {-1,-1};
        }
        int minDist = INT_MAX;
        for(int i=0;i<indexes.size()-1;i++){
            minDist = min(minDist,indexes[i+1]-indexes[i]);
        }
        int maxDist = indexes[indexes.size()-1]-indexes[0];
        return {minDist,maxDist};
    }
};