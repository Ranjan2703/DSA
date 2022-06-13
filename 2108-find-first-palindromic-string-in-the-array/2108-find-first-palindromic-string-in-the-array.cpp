class Solution {
public:
    bool palindrome( string x)
    {
        int i=0;
        int j= x.size()-1;
        
        while(i<j)
        {
             if(x[i] != x[j]) return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        
         for(auto x : words)
         {
              if(palindrome(x))
                  return x;
         }
        return "";
    }
};