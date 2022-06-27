class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum =0;
        
        for(int i=0;i<k;i++)
        {
             sum+=cardPoints[i];
        }
        int maxsum ;
        maxsum =sum;
        
        int i=k-1;
        int j = n-1;
        
        while(i>=0 && i< j)
        {
             sum += cardPoints[j] - cardPoints[i];
             maxsum = max(maxsum,sum);
             i--;
            j--;
        }
        
        return maxsum;
    }
};