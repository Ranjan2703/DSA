class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if(n==0) return 0;
        int curr=0;
        int ans=0;
        
        for(int i=1;i<n;i++)
        {  if(nums[i] != nums[i-1])
             if(nums[i] == nums[i-1]+1)
                 curr++;
            else
            {
                ans = max(ans, curr);
                curr=0;
            }
        }
        
        return max(ans,curr)+1;
    }
};