class Solution {
public:
    int lis(vector<int> &nums,int ind, int prev, vector<vector<int>> &dp)
    {
         if( ind == nums.size()) return 0;
        
        if( dp[ind][prev+1] != -1) return dp[ind][prev+1]; // +1 to handle case when prev is -1
        
         int ans=INT_MIN;
        int len=0;
        int len1=0;
        
         len = 0 + lis(nums,ind+1, prev,dp); // not take condition
        
        if( prev == -1 || nums[ind] > nums[prev]) // take condition
        {
         len1= 1+ lis(nums,ind+1, ind, dp);
        }
       
        ans= max( len, len1);
        
        return dp[ind][prev+1]= ans;
        
        
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return lis(nums, 0,-1,dp);
    }
};