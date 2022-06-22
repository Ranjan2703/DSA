// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array

long long int cntAndMerge(long long int arr[],long long int l,long long int m,long long int r){
   int n1=m-l+1,n2=r-m;
   long long int left[n1],right[n2];
   for(long long int i=0;i<n1;i++){
       left[i]=arr[l+i];
   }
   for(long long int i=0;i<n2;i++){
       right[i]=arr[m+1+i];
   }
   long long int res=0,i=0,j=0,k=l;
   while(i<n1 && j<n2){
       if(left[i]<=right[j])
           arr[k++]=left[i++];
       
       else{
           arr[k++]=right[j++];
           res+=n1-i;
       }
   }
   while(i<n1)
   arr[k++]=left[i++];
   while(j<n2)
   arr[k++]=right[j++];
   return res;
}
long long int mrgSrt(long long int arr[],long long int l,long long int r){
   if(l>=r)return 0;
       
       long long int m=(l+r)/2;
       long long int x=mrgSrt(arr,l,m);
       long long int y=mrgSrt(arr,m+1,r);
       long long int z=cntAndMerge(arr,l,m,r);
   return x+y+z;
}
long long int inversionCount(long long arr[], long long N)
{
   // Your Code Here
  return mrgSrt(arr,0,N-1);
}
};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends