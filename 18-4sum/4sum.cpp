class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int k=j+1,l=n-1;
                while(k<l){
                    long long sum=1LL*nums[i]+1LL*nums[j]+1LL*nums[k]+1LL*nums[l];
                    if(sum==1LL*target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        int temp=k;
                        while(temp<n&&nums[temp]==nums[k])
                        temp++;
                        k=temp;
                        temp=l;
                        while(temp>=0&&nums[temp]==nums[l])
                        temp--;
                        l=temp;
                    }
                    else if(sum<target){
                        int temp=k;
                        while(temp<n&&nums[temp]==nums[k])
                        temp++;
                        k=temp;
                    }
                    else{
                        int temp=l;
                        while(temp>=0&&nums[temp]==nums[l])
                        temp--;
                        l=temp;
                    }
                }
                int temp=j;
                while(temp<n-1&&nums[temp]==nums[j])
                temp++;
                j=temp-1;
            }
            int temp=i;
            while(temp<n-1&&nums[temp]==nums[i])
            temp++;
            i=temp-1;
        }
        return ans;
    }
};