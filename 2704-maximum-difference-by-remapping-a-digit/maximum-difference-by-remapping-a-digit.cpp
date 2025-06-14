class Solution {
public:
    int minMaxDifference(int num) {
        string n=to_string(num);
        string ma=n;
        int d=-1;
        for(auto& it:ma){
            if(it!='9'&&d==-1)
                d=it;
            if(it==d)
            it='9';
        }
        string mi=n;
        char q=mi[0];
        for(auto& it:mi){
            if(it==q)
            it='0';
        }
        int maa=stoi(ma);
        int mii=stoi(mi);
        return maa-mii;
    }
};