class Solution {
public:
//     int solve(string &s, string& w, int m, int n)
//     {
//        if(m == 0 || n==0)
//            return 0;
        
//         if(s[m-1] == w[n-1])
//         {
//             return 1+ solve(s,w,m-1,n-1);
//         }
//         else
//         {
//             return max(solve(s,w,m-1,n) , solve(s,w,m,n-1));
//         }
        
//     }
    
    bool isSubseq(string &s, string w)
    {
        int i =0;
        int j =0;
        
        while(i<s.size() && j<w.size())
        {
            
            if(s[i] == w[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        
        return (j==w.size());
        
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        // int n = words.size();
        // int sz = s.size();
        // int ans =0;
        // for(int i =0;i<n;i++)
        // {   
        //      int m = words[i].size();
        //      if(solve(s, words[i],sz, m) == m)
        //      {
        //         ans++;
        //      }
        // }
        // return ans ;
        
        unordered_map<string, int> umap;
        int ans =0;
        for(int i=0;i<words.size();i++)
        {
            umap[words[i]]++;
            
        }
        
        for(auto m:umap)
        {
             if(isSubseq(s, m.first))
             {
                 ans += m.second;
             }
        }
        return ans;
    }
};