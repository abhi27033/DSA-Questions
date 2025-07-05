class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501];
        memset(freq,0,sizeof(freq));
        for(auto it:arr)freq[it]++;
        for(int i=500;i>0;i--)
        if(freq[i]==i)return i;
        return -1;
    }
};