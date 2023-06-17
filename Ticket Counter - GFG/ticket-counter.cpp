//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        deque<int> q;
        for(int i=1;i<=N;i++)
        q.push_front(i);
        int flg=0;
        int ans=1;
        while(!q.empty())
        {
            if(flg==0)
            {
                int g=K;
            while(g--&&q.size()>1)
            {
                q.pop_back();
            }
            if(q.size()==1)
            {
            ans=q.front();
            break;
            }
            flg=1;
            }
            else
            {
                int g=K;
                while(g--&&q.size()>1)
            {
                q.pop_front();
            }
            if(q.size()==1)
            {
            ans=q.front();
            break;
            }
                flg=0;
            }
            if(q.size()==1)
            {
            ans=q.front();
            break;
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends