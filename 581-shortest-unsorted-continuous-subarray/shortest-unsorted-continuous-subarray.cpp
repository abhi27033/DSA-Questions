class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s=-1,e=-1,n=nums.size();
        for(int i=0;i<n-1;i++)
        if(nums[i]>nums[i+1])e=i;
        for(int i=n-1;i>0;i--)
        if(nums[i]<nums[i-1])s=i;
        if(s==-1)return 0;
        int ma=nums[s],mi=nums[s];
        for(int i=s+1;i<=min(e,n-1);i++)
        {
            ma=max(ma,nums[i]);
            mi=min(mi,nums[i]);
        }
        int i=s-1;
        while(i>=0){
            if(nums[i]>mi)
            {
                ma=max(ma,nums[i]);
                s=i;
                i--;
            }
            else break;
        }
        i=e+1;
        while(i<n){
            if(nums[i]<ma)
            {
                mi=min(mi,nums[i]);
                e=i;
                i++;
            }
            else break;
        }
        i=s-1;
        while(i>=0){
            if(nums[i]>mi)
            {
                ma=max(ma,nums[i]);
                s=i;
                i--;
            }
            else break;
        }
        return e-s+1;
    }
};