class Solution {
public:
bool isv(char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}
    int maxFreqSum(string s) {
        int f1=0,f2=0;
        vector<int> fr(26,0);
        for(auto it:s)fr[it-'a']++;
        for(int i=0;i<26;i++){
            if(isv(i+'a'))
            f1=max(f1,fr[i]);
            else
            f2=max(f2,fr[i]);
        }
        return f1+f2;
    }
};