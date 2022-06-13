class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n= str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>( m+1));
        
        // lcs will give the common element dono string ke then just traverse the matrix and print it
        // just like lcs print 
        
        for(int i=0;i<=n;i++)   
        {
             for(int j =0 ;j<=m;j++)
             {
                  if(i==0 || j==0) dp[i][j]= 0;
                 
                 else if(str1[i-1] == str2[j-1])
                     dp[i][j]= dp[i-1][j-1] +1;
                 
                 else
                     dp[i][j]= max( dp[i-1][j], dp[i][j-1]);
             }
        }
        
        
        int i =n;
        int j = m;
        string res;
        
        while(i>0 && j> 0)
        {
             if( str1[i-1]== str2[j-1])
             {
                  res += str1[i-1];
                  i--;
                 j--;
             }
            else
            {
                 if( dp[i-1][j]> dp[i][j-1])
                 {
                      res +=str1[i-1];
                      i--;
                 }
                else
                {
                     res += str2[j-1];
                    j--;
                }
            }
        }
         while(i> 0) res+= str1[i-1], i--; // if still there is element left in str1
        while(j>0 ) res+= str2[j-1],j--;   // if element left in str2
        reverse(res.begin(), res.end());
        
        return res;
    }
};