class Solution {
public:
    bool f(int i,int j,string &s,string &p,vector<vector<int>> &dp)
    { 
        if(i<0 && j<0) return true;   
        if(j<0 && i>=0) return false;  
        if(i<0 && j>=0)  
        {
            while(j>=0)
            {
                if(p[j]=='*') j-=2;
                else return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j]==s[i] || p[j]=='.') return f(i-1,j-1,s,p,dp);
        
        if(p[j]=='*')
        {
            if(p[j-1]!=s[i] && p[j-1]!='.')
                return dp[i][j]=f(i,j-2,s,p,dp);  
            else
            {
                return dp[i][j]=f(i,j-2,s,p,dp) || f(i-1,j,s,p,dp); 
                
            }
        }
        return dp[i][j]=false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n-1,m-1,s,p,dp);
    }
};