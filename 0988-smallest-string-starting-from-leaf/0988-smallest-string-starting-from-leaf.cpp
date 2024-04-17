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
    string ans;
    void solve(TreeNode* r,string s)
    {
        if(!r)return;
        if(!r->left&&!r->right)
        {
            s+=(char)(r->val+'a');
            reverse(s.begin(),s.end());
            if(ans=="")
                ans=s;
            else
            ans=min(ans,s);
            return ;
        }
        char t=r->val+'a';
        solve(r->left,s+t);
        solve(r->right,s+t);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};