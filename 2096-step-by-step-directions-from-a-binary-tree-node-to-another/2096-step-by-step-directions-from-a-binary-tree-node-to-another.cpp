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

    TreeNode* solve(TreeNode* r,int s,int e)
    {
       if(!r||r->val==s||r->val==e)
           return r;
        TreeNode* a=solve(r->left,s,e);
        TreeNode* b=solve(r->right,s,e);
        if(a&&b)return r;
        if(a)return a;
        return b;
    }
    string f1="",ff="";
    void s1(TreeNode* r,int f,string& a)
    {
        if(!r)return;
        if(r->val==f)
        {
            // cout<<a<<endl;
            f1=a;
            return;
        }
        a+='U';
        s1(r->left,f,a);
        s1(r->right,f,a);
        a.pop_back();
    }
    void s2(TreeNode* r,int f,string& b)
    {
        if(!r)return;
        if(r->val==f)
        {
            // cout<<b<<endl;
            ff=b;
            return;
        }
        // cout<<f<<endl;
        b+='L';
        s2(r->left,f,b);
        b.pop_back();
        b+='R';
        s2(r->right,f,b);
        b.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* temp=solve(root,startValue,destValue);
        string a="",b="",ans="";
        TreeNode* x=temp;
        cout<<x->val<<endl;
        s1(x,startValue,a);
        // cout<<f1<<endl;
        b="";
        ans+=f1;
        s2(temp,destValue,b);
        // cout<<ff<<endl;
        ans+=ff;
        return ans;    
        }
};