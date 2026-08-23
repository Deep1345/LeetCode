// Problem   : 101. Symmetric Tree
// Difficulty: Easy
// Tags      : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// URL       : https://leetcode.com/problems/symmetric-tree/
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
    bool help(TreeNode* left,TreeNode* right){
        if(left==nullptr || right == nullptr){
            return(left==right);
        }
        if(left->val!=right->val){
            return false;
        }
        return help(left->left,right->right) && help(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        return help(root->left,root->right);
    }
};