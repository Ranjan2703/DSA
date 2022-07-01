class Solution {
public:
//     int minHealth(int i, int j, int n, int m, vector<vector<int>> &dungeon,                   vector<vector<int>>& dp)
//     {
//          if( i == n || j ==m) return INT_MAX;
//          if(i == n-1 &&  j== m-1) 
//          {
//               return (dungeon[i][j] <= 0) ? -dungeon[i][j] +1 : 1;
//          }
//         if(dp[i][j] != INT_MAX) return dp[i][j];
         
//         int right = minHealth(i+1,j,n,m,dungeon,dp);
//         int down = minHealth(i,j+1,n,m,dungeon,dp);
        
//         int healthRequired = min(right, down)- dungeon[i][j];
        
//         return dp[i][j]= (healthRequired <= 0) ? 1: healthRequired;
        
            
//     }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp( n+1, vector<int>(m+1,INT_MAX));
        
         dp[n][m-1] =1;
        dp[n-1][m] =1 ;
    
        for(int i =n-1;i>=0;i--)
        {
             for(int j = m -1;j>=0;j--)
             {
                  int healthRequired= min(dp[i+1][j], dp[i][j+1])- dungeon[i][j];
                  dp[i][j] = healthRequired <=0 ? 1 :healthRequired;
             }
        }
        return dp[0][0];
    }
};