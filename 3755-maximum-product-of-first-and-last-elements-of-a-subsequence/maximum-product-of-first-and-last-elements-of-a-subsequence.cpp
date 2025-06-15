class Solution {
public:
    long long maximumProduct(vector<int>& num, int m) {
        int n=num.size();
        vector<vector<long long>> suf(n,vector<long long>(4,1e6));
        vector<long long> nums;
        for(auto it:num)nums.push_back(it);
        int end=nums.back();
        if(end>=0)
        {
            suf[n-1][0]=end;
            suf[n-1][2]=end;
        }
        else
        {
            suf[n-1][1]=end;
            suf[n-1][3]=end;
        }
        for(int i=n-2;i>=0;i--){
            long long maxPos=suf[i+1][0];
            long long maxNeg=suf[i+1][1];
            long long minPos=suf[i+1][2];
            long long minNeg=suf[i+1][3];
            suf[i]=suf[i+1];
            if(nums[i]>=0){
                if(maxPos==1e6)
                suf[i][0]=nums[i];
                else
                suf[i][0]=max(nums[i],maxPos);
                if(minPos==1e6)
                suf[i][2]=nums[i];
                else
                suf[i][2]=min(nums[i],minPos);
            }
            else
            {
                if(maxNeg==1e6)
                suf[i][1]=nums[i];
                else
                suf[i][1]=min(nums[i],maxNeg);
                if(minNeg==1e6)
                suf[i][3]=nums[i];
                else
                suf[i][3]=max(nums[i],minNeg);
            }
        }
        // for(auto it:suf)
        // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<" "<<it[3]<<endl;
        long long ans=-1e16;
        for(int i=0;i<n;i++){
            int next=m-1+i;
            if(next<n){
                long long maxPos=suf[next][0];
                long long maxNeg=suf[next][1];
                long long minPos=suf[next][2];
                long long minNeg=suf[next][3];
                // cout<<nums[i]<<" "<<maxPos<<" "<<maxNeg<<" "<<minPos<<" "<<minNeg<<endl;
                if(nums[i]<0)
                {
                    if(maxNeg!=1e6)
                    ans=max(ans,nums[i]*maxNeg);
                    else if(minNeg!=1e6)
                    ans=max(ans,nums[i]*minNeg);
                    else if(minPos!=1e6)
                    ans=max(ans,nums[i]*minPos);
                    else
                    ans=max(ans,nums[i]*maxPos);
                }
                else if(nums[i]>0){
                    if(maxPos!=1e6)
                    ans=max(ans,nums[i]*maxPos);
                    else if(minPos!=1e6)
                    ans=max(ans,nums[i]*minPos);
                    else if(minNeg!=1e6)
                    ans=max(ans,nums[i]*minNeg);
                    else
                    ans=max(ans,nums[i]*maxNeg);
                }
                else
                ans=max(ans,0LL);
            }
        }
        return ans;
    }
};