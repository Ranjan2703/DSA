class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       
        int st = 0;
        int en = nums.size()-1;
        int mid;
        
        while(st<en)
        { 
              mid = st + (en-st)/2;
            if(nums[mid] > nums[mid+1])
            {
                en= mid;
            }
            else
                st = mid+1;
            
           
        }
        return st;
    }
};