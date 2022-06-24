class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        long sum =0;
        priority_queue<long> q;
        
        for(auto ele : target)
        {
             sum += ele;
            q.push(long(ele));
        }
        
        while(q.top() != 1)
        {
             long top = q.top();
             q.pop();
             sum -= top;
            
            if(sum <= 0 || sum >= top)
            {
                return false;
            }
             
            top = top%sum;
            sum += top;
            
             q.push( top >0  ? top : sum);
                
        }
        
        return true;
    }
};