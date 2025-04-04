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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<vector<TreeNode*>> depth;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> par;
        q.push(root);
        while(q.size()){
            int sz=q.size();
            vector<TreeNode*> temp;
            while(sz--){
                TreeNode* t=q.front();
                temp.push_back(t);
                q.pop();
                if(t->left)
                {
                q.push(t->left);
                par[t->left]=t;
                }
                if(t->right)
                {
                q.push(t->right);
                par[t->right]=t;
                }
            }
            depth.push_back(temp);
        }
        unordered_map<TreeNode*,int> mark;
        for(auto it:depth.back())
        mark[it]=1;
        while(mark.size()>1){
            unordered_map<TreeNode*,int> nm;
            for(auto it:mark)
            nm[par[it.first]]=1;
            mark=nm;
        }
        return mark.begin()->first;
    }
};