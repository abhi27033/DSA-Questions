class Trie{
    public:
        vector<Trie*> child;
        priority_queue<string> topWords;
    Trie(){
        child.resize(26,NULL);
    }
    void addWord(string& word){
        Trie* node=this;
        for(auto it:word){
            if(node->child[it-'a']==NULL){
                node->child[it-'a']=new Trie();
            }
            node=node->child[it-'a'];
            if(node->topWords.size()<3)
            node->topWords.push(word);
            else if(node->topWords.top()>word){
                node->topWords.pop();
                node->topWords.push(word);
            }
        }
    }
    vector<string> suggest(string& word){
        Trie* node=this;
        for(auto it:word){
            if(node->child[it-'a'])
            node=node->child[it-'a'];
            else
            return {};
        }
        vector<string> ans;
        while(node&&node->topWords.size()){
            ans.push_back(node->topWords.top());
            node->topWords.pop();
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans)
        node->topWords.push(it);
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root=new Trie();
        for(auto it:products)
        root->addWord(it);
        vector<vector<string>> ans;
        string word;
        for(auto it:searchWord){
            word+=it;
            ans.push_back(root->suggest(word));
        }
        return ans;
    }
};