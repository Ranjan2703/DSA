// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.size();
	    int m = str2.size();
	    int dp[n+1][m+1];
	    
	    for(int i=0;i<n+1;i++)
	    {
	         for(int j =0;j<m+1;j++)
	         {
	              if(i == 0|| j== 0) dp[i][j] =0;
	              
	              else if(str1[i-1] == str2[j-1])
	              dp[i][j]= dp[i-1][j-1] +1;
	              
	              else
	              dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
  	         }
	    }
	    
	    int ans =0;
	    ans = (n-dp[n][m]) + (m-dp[n][m]);
	    return ans;
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends