class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int str1=0,ans=0,c1=0,str2=1,c2=0,c3=0,c4=0;
        for(auto it:nums){
            if(it%2==str1){
                c1++;
                ans=max(ans,c1);
                str1=1-str1;
            }
            if(it%2==str2){
                c2++;
                ans=max(ans,c2);
                str2=1-str2;
            }
            if(it%2==1)
            {
                c3++;
                ans=max(ans,c3);
            }
            else
            {
                c4++;
                ans=max(ans,c4);
            }
        }
        return ans;
        
    }
};