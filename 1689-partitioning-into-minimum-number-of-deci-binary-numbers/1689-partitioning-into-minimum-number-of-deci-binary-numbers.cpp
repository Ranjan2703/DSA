class Solution {
public:
    int minPartitions(string n) {
        
        int ans = 0;;
        
        for(auto i : n)
        {
             int number = i -'0';
            ans= max(ans, number);
        }
        return ans;
    }
};