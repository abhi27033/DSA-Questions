class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> digits(10,0);
        long long m=n;
        while(n){
            digits[n%10]++;
            n/=10;
        }
        long long q=1;
        while(q<=10LL*m){
            long long f=q;
            vector<int> dd(10,0);
            while(f){
                dd[f%10]++;
                f/=10;
            }
            // for(auto it:dd)cout<<it<<" ";
            // cout<<endl;
            int flg=-1;
            for(int i=0;i<10;i++)
            if(dd[i]!=digits[i]){flg=1;break;}
            if(flg==-1)return true;
            q<<=1LL;
        }
        return false;
    }
};