class Solution {
public:
    int lengthOfLastWord(string s) {
        s+=" ";
        string ans,word;
        for(auto it:s)
        {
            if(it==' ')
            {
                if(word!="")
                ans=word;
                word="";
            }
            else
                word+=it;
        }
        return ans.size();
    }
};