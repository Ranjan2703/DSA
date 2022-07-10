class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        
        vector<int> dp= cost;
        

        for(int i=2 ;i<n;i++){
            dp[i] += min(dp[i-1],dp[i-2]);
        }
       return min(dp[n-1], dp[n-2]);
    }
};