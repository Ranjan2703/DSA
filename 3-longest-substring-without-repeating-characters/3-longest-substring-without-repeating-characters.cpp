class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int> m;
       int n = s.size();
        if(n == 0) return 0;
        int i=0;
        int j =0;
         int ans =INT_MIN;
        while(j<n)
        {
            m[s[j]]++;
            
            if(m.size() == j-i+1)
            {
                 ans= max(ans, j-i+1);
                j++;
            }
            
            else if(m.size() < j-i+1)
            {
                 while(m.size() < j-i+1)
                 {
                      m[s[i]]--;
                     if(m[s[i]] == 0)
                     {
                        m.erase(s[i]);
                     }
                     i++;
                 }
                j++;
            }
        }
        
        return ans;
    }
};