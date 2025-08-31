class Solution {
public:
vector<vector<char>> ans;
bool ispossible(vector<vector<char>>& board,int i,int j, char ch){
    for(int jj=0;jj<9;jj++)if(board[i][jj]==ch)return false;
    for(int ii=0;ii<9;ii++)if(board[ii][j]==ch)return false;
    int r=i/3,c=j/3;
    r*=3,c*=3;
    for(int ii=r;ii<r+3;ii++)
    for(int jj=c;jj<c+3;jj++)
    if(board[ii][jj]==ch)return false;
    return true;
}
    void solve(vector<vector<char>>& board,int i, int j){
        if(i>=9){
            // for(auto it:board){for(auto itt:it)cout<<itt<<" ";cout<<endl;}
            ans=board;
            return;
        }
        if(j>=9){
            solve(board,i+1,0);
            return;
        }
        if(board[i][j]=='.'){
            for(char d='1';d<='9';d++){
                if(ispossible(board,i,j,d)){
                    board[i][j]=d;
                    solve(board,i,j+1);
                    board[i][j]='.';
                }
            }
        }
        else solve(board,i,j+1);
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        board=ans;
    }
};