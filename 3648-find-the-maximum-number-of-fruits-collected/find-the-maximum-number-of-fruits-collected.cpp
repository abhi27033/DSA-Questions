class Solution {
public:
vector<vector<int>> dp;
    int up(vector<vector<int>>& fruits, int i, int j){
        if(i>=fruits.size()||j>=fruits.size()||i==j||i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=fruits[i][j]+max({up(fruits,i+1,j),up(fruits,i+1,j+1),up(fruits,i+1,j-1)});
    }
    int down(vector<vector<int>>& fruits, int i, int j){
        if(i>=fruits.size()||j>=fruits.size()||i==j||i<j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=fruits[i][j]+max({down(fruits,i,j+1),down(fruits,i-1,j+1),down(fruits,i+1,j+1)});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int sum=0,n=fruits.size();
        for(int i=0;i<n;i++){
            sum+=fruits[i][i];
        }
        dp.resize(n,vector<int>(n,-1));
        sum+=up(fruits,0,n-1);
        dp=vector<vector<int>>(n,vector<int>(n,-1));
        sum+=down(fruits,n-1,0);
        return sum;
    }
};