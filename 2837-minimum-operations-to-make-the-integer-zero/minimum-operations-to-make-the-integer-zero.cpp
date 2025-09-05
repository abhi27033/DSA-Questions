class Solution {
public:

    int makeTheIntegerZero(int num1, int num2) {
        for(int i=0;i<=40;i++){
            long long target=num1-1LL*num2*i;
            long long ans=0;
            if(target<i)break;
            while(target>0){
                ans+=(target&1);
                target>>=1;
            }
            if(ans<=i)return i;
        }
        return -1;
    }
};