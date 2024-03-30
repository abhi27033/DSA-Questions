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
    bool solve(TreeNode* r,long l,long h)
    {
        if(!r)return true;
        long d=r->val;
        if(d<=l||d>=h)return false;
        return solve(r->left,l,min(h,d))&&solve(r->right,max(l,d),h);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return solve(root->left,LONG_MIN,root->val)&&solve(root->right,root->val,LONG_MAX);
    }
};