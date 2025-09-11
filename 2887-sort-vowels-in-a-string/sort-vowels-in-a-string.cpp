class Solution {
public:
bool isVowel(char ch)
{
    ch=tolower(ch);
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}
    string sortVowels(string s) {
        string t;
        for(auto it:s)
        if(isVowel(it))
        t+=it;
        sort(t.begin(),t.end());
        int k=0;
        for(int i=0;i<s.size();i++)
        if(isVowel(s[i]))
        s[i]=t[k++];
        return s;
    }
};