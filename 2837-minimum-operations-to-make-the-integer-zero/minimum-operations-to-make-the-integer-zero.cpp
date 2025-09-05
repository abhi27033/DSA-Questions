class Solution {
public:

    int makeTheIntegerZero(int num1, int num2) {
        for(int i=0;i<=40;i++){
            long long target=num1-1LL*num2*i;
            long long ans=0,q=0;
            if(target<=0)break;
            while(target>0){
                ans+=(target&1);
                q++;
                target>>=1;
            }
            if(ans<=i)
            {
                if(i-ans){
                    if(q>1)return i;
                }
                else
                return i;
            }
        }
        return -1;
    }
};