class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l=0,h=nums.back()-nums[0],ans=0;
        if(p==0)return 0;
        while(l<=h){
            int m=l+(h-l)/2,k=0;
            for(int i=1;i<nums.size();i++){
                if(m>=nums[i]-nums[i-1]){
                    i++;
                    k++;
                }
            }
            if(k>=p){
                h=m-1;
                ans=m;
            }
            else l=m+1;
        }
        return ans;
    }
};