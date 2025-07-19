class Solution {
public:
bool comp(string& a,string& b){
    if(a.size()>b.size())return false;
    for(int i=0;i<a.size();i++)
    if(a[i]!=b[i])return false;
    if(a.size()==b.size())return true;
    return b[a.size()]=='/';
}
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        for(int i=0;i<folder.size();i++){
            int j=i+1;
            while(j<folder.size()&&comp(folder[i],folder[j]))
            j++;
            ans.push_back(folder[i]);
            i=j-1;
        }
        return ans;
    }
};