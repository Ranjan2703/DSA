class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum =0;
        
        for(auto z: stones)
        {
             sum+= z;
        }
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        
        for(int i =0;i<=n;i++)
        {
            for(int  j =0;j<=sum;j++)
            {
                  if(i==0) dp[i][j]=0;
                  if(j==0) dp[i][j]= 1;
                     
            }
        }
            
            for(int i =1;i<=n;i++)
            {
                 for(int j =1;j<=sum;j++)
                 {
                      if(i==0) dp[i][j]=0;
                      if(j==0) dp[i][j]= 1;
                     
                     
                     if(stones[i-1]<= j)
                          dp[i][j] = dp[i-1][j] || dp[i-1][j- stones[i-1]];
                     else
                         dp[i][j] = dp[i-1][j];
                 }
            }
          int ans =INT_MAX;
		
        for(int j=0;j<=sum;j++)
        {
          if(dp[n][j])
                ans=min(ans,abs(sum-2*j));  
        }
        
        return ans;
    }
};