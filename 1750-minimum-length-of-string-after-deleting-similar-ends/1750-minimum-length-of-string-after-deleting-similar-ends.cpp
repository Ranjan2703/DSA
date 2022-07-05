class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i =0 ;
        int  j = n-1;
        int count =0;
        
        while( i< j && s[i] == s[j])
        {
            
            char temp = s[i];
            
            while(i<=j &&  s[i] == temp)
            {
                 i++;
            }
            while(i<=j && s[j] == temp)
            {
                 j--;
            }
        }
        return j-i+1;
    }
};