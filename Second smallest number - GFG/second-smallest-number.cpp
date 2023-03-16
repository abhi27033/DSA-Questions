//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        if(D*9<=S)
        return "-1";
        
        string s;
        int a=0;
        while(D>=0)
        {
            if(S-a<10)
            break;
            s+='9';
            a+=9;
            D--;
        }
        //cout<<D;
        int x=D;
        int t=S-a;
        int u=x-2;
        t--;
        if(D>1)
        {
        s+=to_string(t);
        while(u>0)
        {
        s+='0';
        u--;
        }
        s+='1';
        }
        else
        s+=to_string(t+1);
        int flg=0;
        // s[0]=((s[0]-'0')-1)+'0';
        //  s[1]=((s[1]-'0')+1)+'0';
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='9'&&s[i+1]!='9')
            {
                flg=1;
            s[i]=((s[i]-'0')-1)+'0';
            s[i+1]=((s[i+1]-'0')+1)+'0';
            break;
            }
        }
        if(flg==0)
        {
             s[0]=((s[0]-'0')-1)+'0';
             s[1]=((s[1]-'0')+1)+'0';
        }
        reverse(s.begin(),s.end());
        
        return s;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends