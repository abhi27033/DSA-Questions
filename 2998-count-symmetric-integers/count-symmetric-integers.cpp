class Solution {
public:
int isSymmetric(int number){
    string num=to_string(number);
    if(num.size()%2==1)return 0;
    int s=0,n=num.size();
    for(int i=0;i<n/2;i++)
    s+=(num[i]-'0');
    for(int i=n/2;i<n;i++)
    s-=(num[i]-'0');
    return (s==0);
}
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            ans+=isSymmetric(i);
        }
        return ans;
    }
};