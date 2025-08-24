class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int c=0,cz=0,j=0,flg=-1;
        for(auto it:nums){
            cz+=(it==0);
            c+=(it==1);
            while(cz>1){
                cz-=(nums[j]==0);
                c-=(nums[j]==1);
                j++;
            }
            if(it==0)flg=0;
            ans=max(ans,c);
        }
        return ans+flg;
    }
};