class Solution {
public:
    int numSquares(int n) {
        
        //vector for updating the dp array/values
        vector<int> dp(n+1,INT_MAX);
        //base case
        
        dp[0]=0;
        int num = 1;
        
        while(num*num <= n) {
            
        int sq = num*num;
            
        for(int i = sq; i < n+1; i++) {
            
            dp[i] = min(dp[i-sq] + 1,dp[i]);
        }
        num++;
    }
    return dp[n];
    }
};