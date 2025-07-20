class Trie{
public:
    unordered_map<string,Trie*> mp;
    bool deleteChild;
    Trie(){
        mp.clear();
        deleteChild=false;
    }
    void insert(vector<string>& path){
        Trie* current=this;
        for(auto folder:path){
            if(current->mp.find(folder)==current->mp.end())
            current->mp[folder]=new Trie();
            current=current->mp[folder];
        }
    }
};
class Solution {
public:
    string hashCalc(Trie* ptr,unordered_map<string,int>& hashCount){
        vector<string> childHash;
        for(auto child:ptr->mp){
            string folderName=child.first;
            Trie* children=child.second;
            string hash=hashCalc(children,hashCount);
            string finalHash=folderName+'('+hash+')';
            childHash.push_back(finalHash);
        }
        sort(childHash.begin(),childHash.end());
        string concHash="";
        for(auto hash:childHash)
        concHash+=hash;
        if(concHash!="")
        hashCount[concHash]++;
        return concHash;
    }
    string hashCalcbelow(Trie* ptr){
        vector<string> childHash;
        for(auto child:ptr->mp){
            string folderName=child.first;
            Trie* children=child.second;
            string hash=hashCalcbelow(children);
            string finalHash=folderName+'('+hash+')';
            childHash.push_back(finalHash);
        }
        sort(childHash.begin(),childHash.end());
        string concHash="";
        for(auto hash:childHash)
        concHash+=hash;
        return concHash;
    }
    void markNodes(Trie* ptr,unordered_map<string,int>& hashCount){
        string hash=hashCalcbelow(ptr);
        if(hash!=""&&hashCount[hash]>1)
        {
            ptr->deleteChild=true;
            return; // do not go below
        }
        for(auto& child:ptr->mp){
            markNodes(child.second, hashCount);
        }
    }
    void findans(Trie* ptr,vector<vector<string>>& ans,vector<string>& curr){
        for(auto it:ptr->mp){
            if(it.second->deleteChild==true)continue;
            curr.push_back(it.first);
            ans.push_back(curr);
            findans(it.second,ans,curr);
            curr.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie t;
        for(auto path:paths)
        t.insert(path);
        unordered_map<string,int> hashCount;
        Trie* copy=&t;
        hashCalc(copy,hashCount);
        markNodes(copy,hashCount);
        vector<vector<string>> ans;
        vector<string> curr;
        findans(copy,ans,curr);
        return ans;
    }
};