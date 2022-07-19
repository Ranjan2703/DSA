class Solution {
public:
    int solve(int i, int j , vector<int> &nums, vector<vector<int>>&dp)
    {
         if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left1 = nums[i]+ solve(i+2,j,nums,dp);
        int left2 = nums[i]+ solve(i+1,j-1,nums,dp);
        int right1 =nums[j]+ solve(i+1,j-1,nums,dp);
        int right2= nums[j]+ solve(i, j-2,nums,dp);
        
        int x = max(min(left1,left2), min(right1, right2));
        
        return dp[i][j]= x;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int player1 = solve(0, n-1, nums,dp);
        
        int sum =0;
        for(auto it:nums) sum += it;
        
        if(player1 >= sum - player1) return true;
        return false;
    }
};