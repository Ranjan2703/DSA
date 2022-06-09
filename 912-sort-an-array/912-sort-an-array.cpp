class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       
        priority_queue<int, vector<int> , greater<int>> pq;
        
        for(auto z: nums)
        {
             pq.push(z);
        }
        vector<int> ans;
        
        while(!pq.empty())
        {
             ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
        
    } 
    
};