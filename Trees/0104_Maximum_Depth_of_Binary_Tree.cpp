// Problem   : 104. Maximum Depth of Binary Tree
// Difficulty: Easy
// Tags      : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// URL       : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Language  : Cpp
// Date      : 2026-08-23
//

class Solution {
public:
    int solve(TreeNode* root, int depth) {
        if (root == NULL) {
            return depth;
        }

        int left = solve(root->left, depth + 1);
        int right = solve(root->right, depth + 1);

        return max(left, right);
    }

    int maxDepth(TreeNode* root) {
        return solve(root, 0);
    }
};