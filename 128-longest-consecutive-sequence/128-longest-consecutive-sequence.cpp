class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        int maxlen = 0;
        
        for(auto z : nums)
        {
             s.insert(z);
        }
        
        for(auto it : s)
        {
             if(s.count(it -1 )) continue;
            int j =1;
            while(s.count(it +j)) j++;
            maxlen = max(maxlen, j);
                
        }
        return maxlen;
    }
};