class Solution {
public:
    bool static comp(vector<int> &a , vector<int> &b)
    {
         if(a[0]== b[0])
         {
             return a[1]>b[1];
         }
        return a[0] <b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        sort( envelopes.begin(),  envelopes.end(), comp);
        
        vector<int> dp;
       // dp.push_back(envelopes[i][0])
        for(int i=0;i<n;i++)
        {
             // for(int j=0;j<i;j++)
             // {
             //      if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
             //          dp[i] = max(dp[i] , dp[j] +1);
             // }
             //  ans = max(ans, dp[i]);
            int ele = envelopes[i][1];
            int idx = lower_bound(dp.begin(),dp.end(), ele)- dp.begin();
            
            if(idx >= dp.size()) 
                dp.push_back(ele);
            
            else
                dp[idx]= ele;
            
        }
        return dp.size();
    }
};