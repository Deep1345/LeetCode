// Problem   : 100. Same Tree
// Difficulty: Easy
// Tags      : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// URL       : https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return p==q;
        }
        bool leftS = isSameTree(p->left,q->left);
        bool rightS = isSameTree(p->right,q->right);
        if(leftS==true && rightS==true && p->val==q->val){
            return true;
        }
        return false;
    }
};