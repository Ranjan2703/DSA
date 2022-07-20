class Solution {
public:
    
    pair<int,int> solve(vector<int> &arr , int st, int en,vector<vector<pair<int,int>>> &dp)
    {
        if(st == en) 
        {
            return{arr[st],0};
        }
        
       else if(dp[st][en].second != 0) return dp[st][en];
        
        int minsum =INT_MAX;
        int maxleaf = INT_MIN;
        
        for(int i= st; i<en;i++)
        {
             auto left = solve(arr,st,i,dp);
            auto right = solve(arr, i+1, en,dp);
            
            maxleaf= max(left.first, right.first);
            minsum = min(minsum , left.second+right.second+(left.first*right.first));
        }
        return dp[st][en]={maxleaf, minsum};
        
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {-1,0}));
        return solve(arr,0,n-1,dp).second;
        
    }
};