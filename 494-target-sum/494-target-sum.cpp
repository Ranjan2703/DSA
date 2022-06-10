class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int n = nums.size();
        
        int sum =0;
        for(auto z: nums)
        {
             sum +=z;
        }
        
        if(abs(target) > sum || (sum +target)%2 != 0)
            return 0;
        
        sum = (sum + target)/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        
        for(int j=0;j<sum+1;j++)
            dp[0][j]= 0;
        
        dp[0][0] =1;
        
        for(int i=1;i<n+1;i++)
        {
             for(int j=0;j<sum+1;j++)
             {
                  if(nums[i-1] <=j)
                      dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                 
                 else
                     dp[i][j]= dp[i-1][j];
             }
        }
        return dp[n][sum];
    }
};