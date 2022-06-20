class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s1 (words.begin(), words.end());
        set<string> s2 (words.begin(), words.end());
        
        for(auto z : s1)
        {
             for(int i=1;i<z.size();i++)
             {
                 s2.erase(z.substr(i));
             }
        }
        
        int ans =0;
        
        for(auto parts :s2)
        {
             ans += parts.size()+1;
        }
        
        return ans;
    }
};