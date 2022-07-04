class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int ans =0;
        
        
        for(auto num : nums)
        {
             int a = k- num;
            
            if(umap[a] > 0)
            {
                 ans ++;
                umap[a] -= 1;
             }
            else
            {
                 umap[num] ++;
            }
        }
        return ans;
    }
};