class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        int leftsum =0;
        
        for(auto z: nums)
        {
             sum += z;
        }
        
         for(int i=0;i<n;i++)
         {
              if (sum- leftsum - nums[i] == leftsum )
                  return i;
             
             leftsum += nums[i];
         }
        return -1;
    }
};