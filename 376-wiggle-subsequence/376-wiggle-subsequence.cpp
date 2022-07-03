class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int prev_diff=0;
        int maxlen =0;
        
        prev_diff = nums[1]- nums[0];
        if(prev_diff != 0) maxlen=2;
        else maxlen= 1;
        
        for(int i=2;i<n;i++)
        {
           int curr_diff = nums[i]- nums[i-1];
           if((prev_diff >= 0 and curr_diff <0) || (prev_diff <=0 and curr_diff >0))
           {
                maxlen++;
               prev_diff= curr_diff;
           }
        }
        return maxlen;
    }
    
};