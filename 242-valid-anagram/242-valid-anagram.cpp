class Solution {
public:
    bool isAnagram(string s, string t) {
         if (s==t) return true;
        if (s.size()!=t.size()) return false;
        
        unordered_map<char,int> m;
        
        for(auto z :s)
        {
            m[z]++;
        }
        for(auto x :t )
        {
             m[x]--;
            if(m[x] < 0) return false;
        }
        return true;
    }
};