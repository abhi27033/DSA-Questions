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
    int solve(TreeNode* r)
    {
        if(!r)return 0;
        if(r->left&&!r->left->left&&!r->left->right)return r->left->val+solve(r->right);
        return solve(r->left)+solve(r->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root);
    }
};