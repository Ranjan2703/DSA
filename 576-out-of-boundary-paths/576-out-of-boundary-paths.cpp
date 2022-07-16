class Solution {
public:
    int dp[51][51][51];
    int solvedfs(int m , int n , int move,int i, int j)
    {
         int mod = 1e9+7;
        if(i<0 or i>=m  or j<0 or j>=n ) return 1;
        if(move == 0 ) return 0;
        if(dp[i][j][move] != -1) return dp[i][j][move];
        
        int ans=0;
        ans = (ans + solvedfs(m,n,move-1,i+1,j))%mod;
        ans = (ans+solvedfs(m,n, move-1,i-1,j))%mod;
        ans = (ans+ solvedfs(m,n,move-1,i,j-1))%mod;
        ans = (ans+solvedfs(m,n,move-1,i,j+1))%mod;
        
        
     return dp[i][j][move] =ans;
        
        
         
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        
        return solvedfs(m,n,maxMove,startRow,startColumn);
        
    }
};