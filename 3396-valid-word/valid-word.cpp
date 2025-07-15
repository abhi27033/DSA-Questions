class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;
        int fv=-1,fc=-1,flg=-1;
        for(auto it:word){
            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'||it=='A'||it=='E'||it=='I'||it=='O'||it=='U')
            fv=1;
            else if((it>='a'&&it<='z')||(it>='A'&&it<='Z'))
            fc=1;
            else if(it<'0'||it>'9')
            flg=1;
            // cout<<fv<<" "<<fc<<" "<<flg<<endl;
        }
        if(fv==-1||fc==-1||flg==1)return false;
        return true;
    }
};