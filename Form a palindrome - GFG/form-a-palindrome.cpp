// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string s){
    //complete the function here
    string t= s;
    reverse(t.begin(), t.end());
    int n = t.size();
    
    int dp[n+1][n+1];
     for(int i =0;i<=n;i++)
     {
         for(int j = 0;j<=n;j++)
         {
             if(i==0 || j==0) dp[i][j]=0;
             
             else if( s[i-1] == t[j-1])
             dp[i][j]= dp[i-1][j-1] +1;
             
             else
              dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
         }
     }
      int len = dp[n][n];
      return n- len;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends