class Solution {
public:
    int  path(int i, int j,int m,int n,vector<vector<int>> &dp )
    {
        if(i == m-1 && j== n-1) return  1;
        if( j>=n || i>= m) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = path(i+1,j,m,n,dp);
        int down = path(i,j+1,m,n,dp);
        
        return dp[i][j] = up+down;
        
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return path(0,0,m,n,dp);
        
    }
};