// Problem   : 998. Check Completeness of a Binary Tree
// Difficulty: Medium
// Tags      : Tree, Breadth-First Search, Binary Tree
// URL       : https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Language  : Cpp
// Date      : 2026-08-23
//

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr) {
                nullFound = true;
                continue;
            }
            if(nullFound)
                return false;
            q.push(curr->left);
            q.push(curr->right);
        }
        return true;
    }
};