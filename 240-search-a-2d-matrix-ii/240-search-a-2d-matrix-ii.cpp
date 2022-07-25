class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m = matrix[0].size();
        
       int rowindex =0;
       int colindex= m-1;
         
        while(rowindex<n && colindex>=0){
          int element = matrix[rowindex][colindex];
            
            if(element == target){
                return 1;
            }
            if(element>target){
              colindex--;  
            }
            else{
                rowindex++;
            }
        }
        return 0;
    }
};