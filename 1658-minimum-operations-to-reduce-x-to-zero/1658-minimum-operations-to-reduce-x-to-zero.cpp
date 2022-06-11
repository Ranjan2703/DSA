class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int n = nums.size();
        
        int total =0 ;
        for(auto z : nums)
        {
            total  += z;
        }
        
        int target = total -x;
        if(target < 0) return -1;
        if(target == 0) return n;
        int ans = INT_MIN;
        int sum=0;
        
        for(int i=0,j=0;j<n;j++)
        {
             sum += nums[j];
            
            while(sum> target)
            {
                 sum -= nums[i];
                i++;
            }
             if(sum == target )
                  ans = max(ans, j-i+1);
        }
         if(ans == INT_MIN) return -1;
        
          return n - ans;
    }
};