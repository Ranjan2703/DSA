class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
    int n=arr.size(),m=queries.size();
        vector<int> res(m);
        for(int i=1;i<n;i++)
        {
            arr[i]=(arr[i]^arr[i-1]);
        }
        for(int i=0;i<m;i++)
        {
            if(queries[i][0]==0)
            {
                res[i]=arr[queries[i][1]];
            }
            else
            {
                res[i]=(arr[queries[i][1]]^arr[queries[i][0]-1]);
            }
        }
        return res;
    }
};