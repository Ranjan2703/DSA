class Solution {
public:
    // bool static comp(vector<int>&a, vector<int>&b)
    // {
    //     if(a[0]== b[0])
    //         return a[1]<b[1];
    //     else
    //         return a[0]< b[0];
    // }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        
        sort(pairs.begin(), pairs.end());
        vector<int> lis(n,1);
        int ans =1;
        
        for(int i=1;i<n;i++)
        {
             for(int j=0;j<i;j++)
             {
                  if(pairs[j][1] < pairs[i][0])
                  {
                      lis[i] = max(lis[i] , lis[j]+1);
                       ans = max(ans, lis[i]);
                  }
                 
             }
           
        }
        return ans;
    }
};