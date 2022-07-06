class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int start = 0;
        int end = n-1;
       // int ans =0;
        while(start <= end)
        {
             int mid = (start+ end)/2;
             
             if(citations[mid] == n - mid)
             {
                 return citations[mid];
             }
            else if(citations[mid] > n-mid)
            {
                 end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return n-start;
    }
};