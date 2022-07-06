class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
       int n = rectangles.size();
       vector<double> ratio(n);
        
        for(int i=0;i<n;i++)
        {
             
            ratio[i] = double(rectangles[i][1])/ rectangles[i][0];;
        }
        
        long long ans=0;
        unordered_map<double, int> m;
        
         for(int i =0;i<n;i++)
         {
              if(m.find(ratio[i]) != m.end())
                  ans += m[ratio[i]];
              
             m[ratio[i]]++;
         }
         return ans;
    }
};