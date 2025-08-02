class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int ans=0;
        unordered_set<int>st,rec;
        for(int i=0;i<arr.size();i++){
            unordered_set<int> temp;
            temp.insert(arr[i]);
            for(auto it:rec)
            temp.insert(it|arr[i]);
            // for(auto it:temp)cout<<it<<" ";
            // cout<<endl;
            // for(auto it:st)cout<<it<<" ";
            // cout<<endl;
            for(auto it:temp)
            {
                if(st.find(it)==st.end()){
                    ans++;
                    st.insert(it);
                }
            }
            rec=temp;
            // for(auto it:st)cout<<it<<" ";
            // cout<<endl;
            // ans+=();
        }
        return ans;
    }
};