class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> par;
        vector<TreeNode*> lastLevel;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            lastLevel.clear();
            while (sz--) {
                TreeNode* t = q.front();
                q.pop();
                lastLevel.push_back(t);
                if (t->left) {
                    q.push(t->left);
                    par[t->left] = t;
                }
                if (t->right) {
                    q.push(t->right);
                    par[t->right] = t;
                }
            }
        }

        unordered_map<TreeNode*, int> mark;
        for (auto it : lastLevel) 
            mark[it] = 1;

        while (mark.size() > 1) {
            unordered_map<TreeNode*, int> nm;
            for (auto it : mark)
                nm[par[it.first]] = 1;
            mark = nm;
        }

        return mark.begin()->first;
    }
};
