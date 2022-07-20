class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int , int> m;
        int sum =0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum += (hours[i] > 8) ? 1 : -1;
            if(sum >0) ans= i+1;
            
            else
            {
             if(m.find(sum-1) != m.end() )
            {
                ans = max(ans, i-m[sum-1]);
            }
            if(m.find(sum) == m.end())
                m[sum] =i;
            }
        }
        
        return ans;
    }
};