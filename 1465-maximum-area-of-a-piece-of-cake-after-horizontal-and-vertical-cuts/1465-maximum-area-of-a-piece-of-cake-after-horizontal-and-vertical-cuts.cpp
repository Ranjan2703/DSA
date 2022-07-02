class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long m=1000000007;
        long maximum_height=0;
        long maximum_width=0;
        
        horizontalCuts.insert(horizontalCuts.begin(),0);
        verticalCuts.insert(verticalCuts.begin(),0);
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        for(int i=1;i<horizontalCuts.size();i++)
        {
            maximum_height=max(maximum_height,(long)(horizontalCuts[i]-horizontalCuts[i-1]));
        }
        for(int i=1;i<verticalCuts.size();i++)
        {
            maximum_width=max(maximum_width,(long)(verticalCuts[i]-verticalCuts[i-1]));
        }
        return (int)((maximum_height*maximum_width)%m);
    }
};