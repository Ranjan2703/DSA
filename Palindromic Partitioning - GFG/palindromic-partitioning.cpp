// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[501][501];
bool isPlaindrome(string str, int i, int j)
{
     while(i<j)
     {
          if( str[i++] != str[j--]) return false;
     }
     return true;
}
int solve(string &str, int i, int j)
{
     if( i>= j) return 0;
     
      if( dp[i][j] != -1) return dp[i][j];
     
     if( isPlaindrome(str,i,j) ==  true) return 0;
     
    
     int ans= INT_MAX;
     
     for(int k = i;k<=j-1;k++)
     {
          int tempans = solve(str, i, k)+ solve(str,k+1,j) +1;
          
          ans= min(tempans,ans);
     }
     return dp[i][j] = ans;
}
    int palindromicPartition(string str)
    {
        // code here
        memset( dp, -1, sizeof(dp));
        int n = str.size();
        return solve( str ,0,n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends