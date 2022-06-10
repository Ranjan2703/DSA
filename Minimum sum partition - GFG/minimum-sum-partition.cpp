// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range =0;
	    for(int i =0;i<n;i++)
	    {
	         range  += arr[i];
	    }
	    
	    vector<vector<bool>> dp(n+1, vector<bool>(range+1));
	    
	    for(int j =0;j<range+1;j++)
	    {
	         dp[0][j]= false;
	    }
	    for(int i =0;i<n+1;i++)
	    {
	         dp[i][0]= true;
	    }
	    
	    for(int i=1;i<n+1;i++)
	    {
	         for(int j =1;j<range+1;j++)
	         {
	              if(arr[i-1] <=j)
	              dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
	              
	              else
	              dp[i][j]= dp[i-1][j];
	         }
	    }
	    
	    int ans =INT_MAX;
	    
	    for(int i=0;i<=range/2 ;i++)
	    {
	        if( dp[n][i]==true)
	         ans= min(ans, range- 2*i);
	    }
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
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends