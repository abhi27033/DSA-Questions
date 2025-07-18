class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> ma;
        long long mas=0,n=nums.size()/3;
        for(int i=0;i<n;i++){
            ma.push(nums[i]);
            mas+=nums[i];
        }
        vector<long long> prefix(3*n,0);
        prefix[n-1]=mas;
        for(int i=n;i<3*n;i++){
            if(ma.top()>nums[i]){
                mas-=ma.top();
                ma.pop();
                ma.push(nums[i]);
                mas+=nums[i];
            }
            prefix[i]=mas;
        }
        priority_queue<int,vector<int>,greater<int>> mi;
        long long mis=0;
        for(int i=3*n-1;i>=2*n;i--){
            mi.push(nums[i]);
            mis+=nums[i];
        }
        vector<long long> suffix(3*n,0);
        suffix[2*n]=mis;
        for(int i=2*n-1;i>=0;i--){
            if(mi.top()<nums[i]){
                mis-=mi.top();
                mi.pop();
                mi.push(nums[i]);
                mis+=nums[i];
            }
            suffix[i]=mis;
        }
        // for(auto it:prefix)
        // cout<<it<<" ";
        // cout<<endl;
        // for(auto it:suffix)
        // cout<<it<<" ";
        // cout<<endl;
        long long ans=LONG_MAX;
        for(int i=n-1;i<2*n;i++)
        ans=min(ans,prefix[i]-suffix[i+1]);
        return ans;
    }
};