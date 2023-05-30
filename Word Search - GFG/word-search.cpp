//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int idx) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx])
            return false;
        if (idx == word.size() - 1)
            return true;
        char ch = board[i][j];
        board[i][j] = '?';
        bool found = solve(board, word, i + 1, j, idx + 1) ||
                     solve(board, word, i - 1, j, idx + 1) ||
                     solve(board, word, i, j + 1, idx + 1) ||
                     solve(board, word, i, j - 1, idx + 1);
        board[i][j] = ch;
        return found;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && solve(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends