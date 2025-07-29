class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> bits(32,0);
        int n=nums.size();
        vector<int> arr(n,1);
        int orr=nums.back();
        for(int i=0;i<32;i++)
        bits[i]+=((orr>>i)&1);
        int j=n-1;
        for(int i=n-2;i>=0;i--){
            orr|=nums[i];
            for(int ii=0;ii<32;ii++)
            bits[ii]+=((nums[i]>>ii)&1);
            while(j>i){
                int flg=-1;
                vector<int> tempbits=bits;
                for(int b=0;b<32;b++){
                    if((nums[j]>>b&1)){
                        if(tempbits[b]>1)
                        tempbits[b]--;
                        else
                        {
                            flg=1;
                            break;
                        }
                    }
                }
                if(flg==1)break;
                bits=tempbits;
                j--;
            }
            arr[i]=j-i+1;
        }
        return arr;
    }
};