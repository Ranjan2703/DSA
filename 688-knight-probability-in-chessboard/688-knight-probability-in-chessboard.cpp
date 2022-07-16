class Solution {
public:
    double dp[26][26][101];
    double solve(int n, int k , int r, int c){
        
        
        if(r<0 || c<0 || r>=n || c>= n||k<0 ) return 0;
        if(k == 0 ) return 1;
        if(dp[r][c][k] != 0.0) return dp[r][c][k];
        double res =0;
        res =  solve(n,k-1,r-2,c-1)+
               solve(n,k-1,r-2,c+1)+
               solve(n,k-1,r+1,c-2)+
               solve(n,k-1,r+1,c+2)+
               solve(n,k-1,r-1,c-2)+
               solve(n,k-1,r-1,c+2)+
               solve(n,k-1,r+2,c-1)+
               solve(n,k-1,r+2,c+1);
        
        return dp[r][c][k]= res/8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
        double ans =0;
         memset(dp,0.0,sizeof(dp));
         ans = solve(n,k,row,column);
        return ans;
    }
};