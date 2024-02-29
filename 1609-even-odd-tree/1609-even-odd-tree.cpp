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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(q.size())
        {
            int s=q.size();
            int p=-1;
            while(s--)
            {
                TreeNode* t=q.front();
                q.pop();
                if(!(l&1))
                {
                 if(!(t->val&1)||(p>=t->val&&p!=-1))
                 {
                     // cout<<l<<" "<<t->val<<" "<<p<<endl;
                     return false;
                 }
                p=t->val;
                }
                else
                {
                    if(t->val&1||(p<=t->val&&p!=-1))
                    {
                        // cout<<l<<" "<<t->val<<" "<<p<<endl;
                        return false;
                    }
                    p=t->val;
                }
                if(t->left)
                        q.push(t->left);
                if(t->right)
                        q.push(t->right);
            }
            l++;
        }
        return true;
    }
};