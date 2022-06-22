class Solution {
public:
    int ans;
    void merge(vector<int>&nums, int l, int mid, int h)
    {
         int i= l;
         int j = mid+1;
        
        while(i<= mid && j<= h)
        {
             if((long) nums[i] > (long) 2*nums[j])
             {
                 j++;
                 ans+= (mid-i+1);
             }
             else
                 i++;
        }
        sort(nums.begin()+l, nums.begin()+h+1);
    }
    void mergesort(vector<int> &nums, int l , int h )
    {
         if( l== h) return ;
        int mid = (l+h)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1, h);
        merge(nums,l,mid,h);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int l =0;
        int h =n-1;
        ans =0;
        mergesort(nums,l,h);
        return ans;
    }
};