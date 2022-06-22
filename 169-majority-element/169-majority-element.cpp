class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //APPORACH N0.1 TC-O(N);
        
//         unordered_map<int,int> m;
        
//         for(auto z : nums)
//         {
//              m[z]++;
//         }
//         for(auto it : m)
//         {
//              if(it.second > nums.size()/2)
//                  return it.first;
//         }
//         return -1;
        
        
        // APPROACH N0. 2 TC- 0(N LOGN)
//         sort(nums.begin(), nums.end());
        
//         return nums[nums.size()/2];
        
        
        // APPROACH N0-3
        
        int n = nums.size();
        int ele;
        int count=0;
        
        for(int i =0;i<n;i++)
        {
             if( count == 0)
             {
                  ele= nums[i];
             }
            if( ele == nums[i])
            {
                 count++;
            }
            
            else
                count -= 1;
        }
        
        
        return ele;
        
    }
};