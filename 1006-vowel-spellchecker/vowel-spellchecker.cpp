class Solution {
public:
unordered_map<string,vector<pair<string,int>>> mp;
unordered_set<string> str;
set<char> st={'a','e','i','o','u'};
    void solve(string& s, int i, int& ma, string& an){
        if(i==s.size()){
            auto it=check(s);
            if(it.second<ma){
                ma=it.second;
                an=it.first;
            }
            return;
        }
        // cout<<s[i]<<endl;
        if(st.find(s[i])!=st.end()){
            char ch=s[i];
            for(auto it:st){
                s[i]=it;
                solve(s,i+1,ma,an);
                s[i]=ch;
            }
        }
        solve(s,i+1,ma,an);
    }
    pair<string,int> check(string s){
        if(mp.find(s)!=mp.end())
        return mp[s][0];
        return {"",INT_MAX};
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int i=0;
        for(auto it:wordlist){
            string bk=it;
            transform(it.begin(), it.end(), it.begin(), ::tolower);
            mp[it].push_back({bk,i});
            str.insert(bk);
            i++;
        }
        vector<string> ans;
        for(auto it:queries){
            if(str.find(it)!=str.end()){
                ans.push_back(it);
            }
            else{
                transform(it.begin(), it.end(), it.begin(), ::tolower);
                string caps=check(it).first;
                if(caps!="")
                ans.push_back(caps);
                else{
                    // cout<<it<<endl;
                    string fin;
                    int n=wordlist.size();
                    solve(it,0,n,fin);
                    ans.push_back(fin);
                }
            }
        }
        return ans;
    }
};