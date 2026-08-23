// Problem   : 1207. Delete Nodes And Return Forest
// Difficulty: Medium
// Tags      : Array, Hash Table, Tree, Depth-First Search, Binary Tree
// URL       : https://leetcode.com/problems/delete-nodes-and-return-forest/
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
    TreeNode* del(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans){
        if(root==NULL){
            return NULL;
        }
        root->left = del(root->left,st,ans);
        root->right = del(root->right,st,ans);
        if(st.find(root->val)!=st.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return NULL;
        }
        else{
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(auto it: to_delete){
            st.insert(it);
        }
        vector<TreeNode*> ans;
        root = del(root,st,ans);
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};