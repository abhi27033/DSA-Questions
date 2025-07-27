class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ma=0,ans=0;
        for(int i=0;i<arr.size();i++){
            ma=max(ma,arr[i]);
            if(ma<=i)ans++;
        }
        return ans;
    }
};