class Solution {
public:
    int  solveDfs(int &n, int &m , int i , int j , vector<vector<int>> &grid)
    {
       if(i<0  || i>=n || j<0 || j>=m || grid[i][j] ==0) return 0;
        
        grid[i][j] = 0;
        
        return 1+solveDfs(n,m,i+1,j,grid)+solveDfs(n,m,i-1,j,grid)+solveDfs(n,m,i,j-1,grid)+                           solveDfs(n,m,i,j+1, grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       
        int n= grid.size();
        int m = grid[0].size();
        int ans =0;
        for(int i=0;i<n;i++)
        {
             for(int j =0;j<m;j++)
             {   
                 if(grid[i][j] == 1)
                 {
                    int temp = solveDfs(n,m,i,j,grid);
                    ans = max(ans, temp); 
                 }
                 
             }
        }
        return ans;
    }
};