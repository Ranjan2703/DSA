class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        int maxindex=0;
        
        for(int i=1;i<n;i++)
        {
             for(int j =0;j<i;j++)
             {
                  if(nums[i]% nums[j] == 0 and dp[i] < dp[j]+1)
                  {
                      
                      dp[i]= dp[j]+1;
                      parent[i]=j;
                      
                      if(dp[i] > dp[maxindex]) maxindex = i;
                  }
             }
        }
        
        vector<int> ans ;
        
        for(;maxindex >=0 ; maxindex = parent[maxindex])
        {
             ans.push_back(nums[maxindex]);
             //index= parent[index];
        }
        return ans;
    }
};