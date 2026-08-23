// Problem   : 103. Binary Tree Zigzag Level Order Traversal
// Difficulty: Medium
// Tags      : Tree, Breadth-First Search, Binary Tree
// URL       : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Language  : Cpp
// Date      : 2026-08-23
//

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool ltor = true;
        while (!dq.empty()) {
            int n = dq.size();
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                TreeNode* node;
                if (ltor) {
                    node = dq.front();
                    dq.pop_front();
                    if (node->left)
                        dq.push_back(node->left);
                    if (node->right)
                        dq.push_back(node->right);
                }
                else {
                    node = dq.back();
                    dq.pop_back();
                    if (node->right)
                        dq.push_front(node->right);
                    if (node->left)
                        dq.push_front(node->left);
                }
                temp.push_back(node->val);
            }
            ans.push_back(temp);
            ltor = !ltor;
        }
        return ans;
    }
};