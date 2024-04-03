class Solution {
public:
    bool solve(vector<vector<char>>& board,int i,int j,string& w,int x)
    {
        if(x==w.size())
            return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||w[x]!=board[i][j])
            return false;
        char t=board[i][j];
        board[i][j]='&';
        bool a=solve(board,i+1,j,w,x+1);
        bool b=solve(board,i,j+1,w,x+1);
        bool c=solve(board,i-1,j,w,x+1);
        bool d=solve(board,i,j-1,w,x+1);
        board[i][j]=t;
        return a||b||c||d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    // cout<<i<<" "<<j<<endl;
                    if(solve(board,i,j,word,0))
                        return true;
                }
            }
        }
        return false;
    }
};