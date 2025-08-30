class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(10,0)),col(9,vector<int>(10,0)),box(9,vector<int>(10,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int dig=board[i][j]-'0';
                    int c=j/3,r=i/3;
                    int boxnum=r*3+c%3;              
                    if(dig<=0||dig>9)return false;
                    if(row[i][dig]!=0||col[j][dig]!=0||box[boxnum][dig]!=0)return false;
                    row[i][dig]++;
                    col[j][dig]++;
                    box[boxnum][dig]++;
                }
            }
        }
        return true;
    }
};