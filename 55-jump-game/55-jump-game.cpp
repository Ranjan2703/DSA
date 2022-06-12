class Solution {
public:
    bool canJump(vector<int>& nums) {
       
        int n = nums.size();
        int steps =0;
        
        for(int i= 0;i<n;i++)
        {
             if( i> steps) return false;
            
            steps = max( steps, i+nums[i]);
        }
         return true;
    }
};