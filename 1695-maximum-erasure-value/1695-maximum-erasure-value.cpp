class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> m;
        int sum =0;
        int i=0;
        int j =0;
        int ans =INT_MIN;
        
        while(j<n)
        {
            m[nums[j]]++;
            sum += nums[j];
            
            if(m.size()== j-i+1)
            {
             ans = max(ans, sum);
                j++;
            }
            else if(m.size()<j-i+1)
            {
                while(m.size()<j-i+1)
                {
                    m[nums[i]]--;
                    if(m[nums[i]]== 0)
                    {
                        m.erase(nums[i]);
                    }
                    sum -= nums[i];
                    
                    i++;
                }
                j++;
            }
            
        }
        
        return ans;
    }
};