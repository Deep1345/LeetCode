// Problem   : 662. Maximum Width of Binary Tree
// Difficulty: Medium
// Tags      : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// URL       : https://leetcode.com/problems/maximum-width-of-binary-tree/
// Language  : Cpp
// Date      : 2026-08-23
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        while(!q.empty()){
            unsigned long long sIndex = q.front().second;
            unsigned long long eIndex = q.back().second;
            int currWidth = eIndex-sIndex+1;
            maxWidth = max(maxWidth,currWidth);
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front().first;
                unsigned long long ind = q.front().second;
                q.pop();
                if(node->left){
                    q.push({node->left,2*ind+1});
                }
                if(node->right){
                    q.push({node->right,2*ind+2});
                }
            }
        }
        return maxWidth;
    }
};