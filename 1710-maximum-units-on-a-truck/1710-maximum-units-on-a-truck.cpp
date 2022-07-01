class Solution {
public:
    bool static comp(vector<int> a, vector<int> b)
    {
         return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
       sort(boxTypes.begin(), boxTypes.end(),comp);
       int maxUnit=0;
      // int currSize;
        
    for(auto it :boxTypes)
    {
        if(truckSize >= it[0])
        {
             truckSize -= it[0];
            maxUnit += it[0]*it[1];
        }
        else
        {
            maxUnit += truckSize *it[1];
             return maxUnit;
        }
        
    }
         return maxUnit;
        
        
        
    }
};