class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int idx,vector<int> &dp)
    {
        if(idx>= days.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        //day1 pass
        int a = costs[0] +solve(days,costs,idx+1,dp);
        
        int i;
        
        for( i= idx; i<days.size() && days[i] < days[idx] +7 ;i++);
         
        int b = costs[1]+ solve(days,costs,i,dp);
        
        for( i= idx; i<days.size() && days[i] < days[idx] +30 ;i++);
        
        int c = costs[2]+ solve(days,costs,i,dp);
        
        
        return dp[idx]= min(a, min(b , c));
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solve(days,costs,0, dp);
    }
};