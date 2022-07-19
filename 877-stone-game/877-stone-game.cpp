class Solution {
public:
    int solve(int idx, int n , vector<int> &piles,vector<vector<int>> &dp)
    {
        if(idx > n) return 0;
        if(dp[idx][n] != -1) return dp[idx][n];
        int left1= piles[idx] + solve(idx+2, n,piles,dp);
        int left2 = piles[idx] + solve(idx+1, n-1, piles,dp);
        int right1 = piles[n] + solve(idx+1, n-1, piles,dp);
        int right2 = piles[n] + solve(idx, n-2, piles,dp);
        
        int x=0;
        x = max(min(left1,left2), min(right1, right2));
        
        return dp[idx][n]= x;
    }
    bool stoneGame(vector<int>& piles) {
       int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int alice= solve(0,n-1,piles,dp);
        
        int sum =0;
        for(auto it : piles) sum += it;
        
        if(alice >= sum - alice ) return true;
        
        return false;
        
    }
};