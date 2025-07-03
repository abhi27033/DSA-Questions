class Solution {
public:
int lessthan2pow(int n){
    int x=1;
    while(x<n)
    x<<=1;
    return x>>1;
}
    char kthCharacter(int k) {
    int ans=0;
    while(k!=1)
    {
        k-=lessthan2pow(k);
        ans++;
    }
    return ans+'a';  
    }
};