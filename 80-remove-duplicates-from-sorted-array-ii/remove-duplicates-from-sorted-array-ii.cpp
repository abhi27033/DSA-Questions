class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx1=0,cnt=0,prv=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(prv!=nums[i])
            {
                prv=nums[i];
                cnt=1;
            }
            if(cnt<=2)
            {
                cnt++;
                nums[idx1++]=nums[i];
            }
        }
        return idx1;
    }
};