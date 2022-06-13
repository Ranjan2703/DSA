class Solution {
public:
 /*   int solve( int i,int j,vector<vector<int>> &dp,vector<vector<int>>& triangle ){
        if(i== triangle.size()-1) return triangle[triangle.size()-1][j];
        
        if(dp[i][j] !=-1 ) return dp[i][j];
        
        return dp[i][j]= triangle[i][j]+ min(solve(i+1,j,dp,triangle),solve(i+1,j+1,dp,triangle));
    }
    */
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        int m= n;
        vector<vector<int>> dp(n,vector<int>(m,0));
        //return solve(0,0,dp,triangle);
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                
                int down= triangle[i][j]+dp[i+1][j];
                int diagonal= triangle[i][j]+dp[i+1][j+1];
                
                dp[i][j]= min(down, diagonal);
            }
        }
        return dp[0][0];
        
    }
};