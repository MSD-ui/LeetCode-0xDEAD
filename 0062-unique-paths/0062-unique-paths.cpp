class Solution {
public:
    int solve(int row,int col,vector<vector<int>>&dp)
    {
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;

        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=solve(row-1,col,dp) + solve(row,col-1,dp);
    }

    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
        
    }
};