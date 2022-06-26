class Solution {
public:
   int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> v(n);
        for(int i=0; i<n; i++)
            v[i] = nums2[i] - nums1[i];
        
        int sum1 = 0; for(int i=0; i<n; i++) sum1 += nums1[i];
        int sum2 = 0; for(int i=0; i<n; i++) sum2 += nums2[i];
        
        int maxx = 0, curr = 0;
        for(int i=0; i<n; i++){
            curr += v[i];
            if(curr < 0) curr = 0;
            maxx = max(maxx, curr);
        }
        
        int minn = 0; curr = 0;
        for(int i=0; i<n; i++){
            curr -= v[i];
            if(curr < 0) curr = 0;
            minn = max(minn, curr);
        }
        return max(sum1 + maxx, sum2 + minn);
    }
};