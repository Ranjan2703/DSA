class Solution {
public:
    int minDeletions(string s) {
        
        // T.C = (O + K^2 Logk)
       int n = s.size();
        
        priority_queue<int> q;
        
        vector<int> frq(26,0);
        
       
        
        for(auto x:s)
        {
           frq[x-'a']++; 
        }
        
        int minDelete=0;
        
        for(int i=0;i<26;i++)
        {   
            if(frq[i]> 0)
            q.push(frq[i]);
            
        }
        
        while(q.size()>1)
        {
            int top= q.top();
              q.pop();
            
            if(q.top()== top)
            {
               if(top-1>0)
                q.push(top-1);
                
                minDelete++;
            }
            
        }
        return minDelete;
    }
};