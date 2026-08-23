// Problem   : 543. Diameter of Binary Tree
// Difficulty: Easy
// Tags      : Tree, Depth-First Search, Binary Tree, DP on Trees
// URL       : https://leetcode.com/problems/diameter-of-binary-tree/
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
    int diameter = 0;
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};