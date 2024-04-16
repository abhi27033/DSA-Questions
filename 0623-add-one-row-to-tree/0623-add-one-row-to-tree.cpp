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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        depth--;
        if(depth==0)
        {
            TreeNode* r=new TreeNode(val);
            r->left=root;
            return r;
        }
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(q.size())
        {
            int s=q.size();
            while(s--)
            {
                TreeNode* t=q.front();
                q.pop();
                if(l==depth-1)
                {
                    TreeNode* t1=t->left;
                    TreeNode* t2=t->right;
                    t->left=new TreeNode(val);
                    t->right=new TreeNode(val);
                    t->left->left=t1;
                    t->right->right=t2;
                }
                else
                {
                    if(t->left)
                        q.push(t->left);
                    if(t->right)
                        q.push(t->right);
                }
                
            }
            l++;
        }
        return root;
    }
};