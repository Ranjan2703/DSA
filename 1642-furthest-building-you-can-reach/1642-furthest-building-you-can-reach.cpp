class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        int n = nums.size();
        priority_queue<int> q;
        
        int i=0;
         for(i;i<n-1;i++)
         {
             if(nums[i] >nums[i+1]) continue;
             
             int diff = nums[i+1]- nums[i];
             
             if(diff <= bricks)
             {
                bricks -= diff;
                 q.push(diff);
             }
             
             else if(ladders >0)
             {
                 
                 if(q.size())
                 {
                     int x = q.top();
                     if(x >diff)
                     {
                         bricks += x;
                         q.pop();
                         bricks -= diff;
                         q.push(diff);
                     }
                 }
                 ladders--;
             }
              else
                  break;
         }
         return i;
    }
};