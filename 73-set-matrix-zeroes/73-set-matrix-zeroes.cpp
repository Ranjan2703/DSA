class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
             for(int j =0;j<m;j++)
             {
                  if( matrix[i][j]== 0 )
                      v.push_back({i,j});
                      
             }
        }
        
        int k =0;
        while( k< v.size())
        {
          int r = v[k].first;
          int c = v[k].second;
            
            // set column zero
            
            for(int j =0;j<m;j++)
            {
                 matrix[r][j]= 0;
                
            }
            
            // set row zero
            for(int i=0;i<n;i++)
            {
                 matrix[i][c] =0;
            }
            k++;
        }
        
        
                  
    }
};