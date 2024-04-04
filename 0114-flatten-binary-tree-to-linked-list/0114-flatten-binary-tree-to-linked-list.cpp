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
    TreeNode* solve(TreeNode* r)
    {
        if(!r)return NULL;
        TreeNode* left=solve(r->left);
        TreeNode* right=solve(r->right);
        r->left=NULL;
        if(left)
        {
        r->right=left;
        while(left->right)
            left=left->right;
        left->right=right;
        }
        else
        r->right=right;
        return r;
    }
    void flatten(TreeNode* root) {
        root=solve(root);
    }
};