class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>gap;
        gap.push_back(startTime[0]);
        for(int i=1;i<n;i++)
        gap.push_back(startTime[i]-endTime[i-1]);
        gap.push_back(eventTime-endTime.back());
        vector<int> maxPrefix=gap;
        for(int i=1;i<gap.size();i++)
        maxPrefix[i]=max(maxPrefix[i-1],gap[i]);
        vector<int> maxSuffix=gap;
        for(int i=gap.size()-2;i>=0;i--)
        maxSuffix[i]=max(maxSuffix[i+1],gap[i]);
        int ans=0;
        // for(auto it:gap)
        // cout<<it<<" ";
        // cout<<endl;
        // for(auto it:maxPrefix)
        // cout<<it<<" ";
        // cout<<endl;
        // for(auto it:maxSuffix)
        // cout<<it<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            int left=0,right=0;
            if(i>0)
            left=maxPrefix[i-1];
            if(i+2<gap.size())
            right=maxSuffix[i+2];
            int temp=gap[i]+gap[i+1];
            if(max(left,right)>=(endTime[i]-startTime[i]))
            temp+=endTime[i]-startTime[i];
            ans=max(ans,temp);
        }
        return ans;
    }
};