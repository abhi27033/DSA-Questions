class Solution {
public:
    int comp(string& a,string& b)
    {
        int i=0,j=0,n=a.size(),m=b.size();
        while(i<n&&a[i]=='0')
            i++;
        while(j<m&&b[j]=='0')
            j++;
        string x,y;
        while(i<n)
            x+=a[i++];
        while(j<m)
            y+=b[j++];
        if(x=="")x="0";
        if(y=="")y="0";
        int aa=stoi(x);
        int bb=stoi(y);
        // cout<<aa<<" "<<bb<<endl;
        if(aa>bb)return 1;
        if(bb>aa)return -1;
        return 0;
    }
    int compareVersion(string version1, string version2) {
        int c1=0,c2=0;
        for(auto it:version1)
            c1+=(it=='.');
        for(auto it:version2)
            c2+=(it=='.');
        if(c1>c2)
        {
            int diff=c1-c2;
            while(diff--)
                version2+=".0";
        }
        if(c2>c1)
        {
            int diff=c2-c1;
            while(diff--)
                version1+=".0";
        }
        version1+='.';
        version2+='.';
        int i=0,j=0,n=version1.size(),m=version2.size();
        while(i<n&&j<m)
        {
            string ch,ch1;
            while(i<n&&version1[i]!='.')
                ch+=version1[i++];
            while(j<m&&version2[j]!='.')
                ch1+=version2[j++];
            int x=comp(ch,ch1);
            // cout<<x<<endl;
            if(x==1||x==-1)return x;
            i++;
            j++;
        }
        return 0;
    }
};