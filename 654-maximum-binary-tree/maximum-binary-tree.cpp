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
TreeNode* solve(vector<int>& nums,int l,int r){
    if(l>r)return NULL;
    int ma=INT_MIN,maidx=-1;
    for(int i=l;i<=r;i++){
        if(ma<=nums[i]){
            ma=nums[i];
            maidx=i;
        }
    }
    TreeNode* root=new TreeNode(ma);
    root->left=solve(nums,l,maidx-1);
    root->right=solve(nums,maidx+1,r);
    return root;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};