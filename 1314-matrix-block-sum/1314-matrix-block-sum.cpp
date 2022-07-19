class Solution {
public:
    int solvesum (int i,int j, int k,vector<vector<int>>& mat)
    {   
        int n = mat.size();
        int m = mat[0].size();
        
        int s1= max(0,i-k);
        int s2 = max(0,j-k);
        
        int e1 =min(n-1,i+k);
        int e2= min(m-1,j+k);
        
        int sum =0;
        
        for(int p = s1 ;p<=e1 ;p++)
        {
             for(int q = s2;q<=e2;q++)
             {
                 
                 sum += mat[p][q];
             }
        }
        return sum;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        vector<vector<int>> arr(mat.size(),vector<int>(mat[0].size(),0));
        for(int i =0;i<mat.size();i++)
        {
             for(int j =0;j<mat[i].size();j++)
             {
                 arr[i][j]= solvesum(i,j,k,mat); 
             }
        }
        
        return arr;
    }
};