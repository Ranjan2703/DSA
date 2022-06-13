class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
    int low = -1,high =0;
        while(high<nums.size())
        {
            if(nums[high] != val)
                nums[++low] = nums[high];
            high++;
        }
        return low+1;
        
    }
};