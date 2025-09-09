class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> ar(n+1,0);
        ar[0]=1;
        int m=1e9+7;
        for(int i=0;i<=n;i++){
            if(ar[i]>=1){
                for(int j=i+delay;j<min(n+1,i+forget);j++){
                    ar[j]=(ar[i]%m+ar[j]%m)%m;
                }
            }
        }
        int ans=0;
        int i=n-1;
        while(i>=0&&forget--){
            ans=(ar[i]%m+ans%m)%m;
            i--;
        }
        return ans%m;
    }
};
// 1 . 1 1
//       . 1 1
//         . 1 1
