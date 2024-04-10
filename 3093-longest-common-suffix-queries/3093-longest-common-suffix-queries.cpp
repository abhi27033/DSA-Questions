class TrieNode{
    public:
    char data;
    int slen;
    int sidx;
    TrieNode*children[26];

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++) children[i]=NULL;
        sidx=-1;
        slen=INT_MAX;
    }
};

class Trie{
    private:
    void insertTries(TrieNode*root,string word,int index){

        int n=word.size();
        for(int k=n-1;k>=0;--k){

            int idx=(word[k]-'a');

            if(root->children[idx]!=NULL){

                if(root->children[idx]->slen==n){
                    root->children[idx]->sidx=min(root->children[idx]->sidx,index);
                }
                else if(root->children[idx]->slen>n){
                    root->children[idx]->slen=n;
                    root->children[idx]->sidx=index;
                }
            }
            else{
                TrieNode*child=new TrieNode(word[k]);
                root->children[idx]=child;
                child->slen=n;
                child->sidx=index;
            }
            root=root->children[idx];
        }
    }

    int querySolver(TrieNode*root,string query){
        int ans=1;
        for(int k=query.size()-1;k>=0;k--){
            int idx=query[k]-'a';
            ans=root->sidx;
            if(root->children[idx]==NULL){
                return ans;
            }
            root=root->children[idx];
        }
        return root->sidx;
    }

    public:
    TrieNode*root=new TrieNode('\0');
    void insertIntoTrie(vector<string>words){
        int minlen=INT_MAX,minidx=-1;
        for(int i=0;i<words.size();i++){
            TrieNode*temphead=root;
            if(minlen>words[i].size())
            {
                minlen=words[i].size();
                minidx=i;
            }
            // cout<<words[i]<<endl;
            insertTries(temphead,words[i],i);
            
        }
        cout<<minidx<<endl;
        root->sidx=minidx;
    }
    int queryIntoTrie(string query){
        TrieNode*temphead=root;
        return querySolver(temphead,query);
    }

};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie*t=new Trie();
        t->insertIntoTrie(wordsContainer);
        vector<int>ans;
        for(int i=0;i<wordsQuery.size();i++){
            ans.push_back(t->queryIntoTrie(wordsQuery[i]));
        }
        return ans;
    }
};