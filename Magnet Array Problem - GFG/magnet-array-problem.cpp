// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

    class Solution{
    
    private:
    
    double calcLeftForces(double magnets[], double mid, int i, int n){
        double leftForce = 0;
        for(int j=i; j< n; j++){
            leftForce += 1/(magnets[j] - mid);
        }
        
        return leftForce;
    }
    
    double calcRightForces(double magnets[], double mid, int i, int n){
        double rightForce = 0;
        for(int j=i-1; j >= 0; j--){
            rightForce += 1/(mid - magnets[j]);
        }
        
        return rightForce;
    }
    
    public:
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
         
         for(int i=0; i< n-1; i++){
             double left = magnets[i];
             double right = magnets[i+1];
             double mid = left;
             //Binary Search
             while(left <= right){
                 
                mid = left + (right - left)/2;
                double leftForces = calcLeftForces(magnets, mid, i, n);
                double rightForces = calcRightForces(magnets, mid, i, n);
                
                if(abs(leftForces - rightForces) < 0.000001){
                    break;
                }else if(leftForces < rightForces){
                    left = mid;
                }else{
                    right = mid;
                }
             }
             getAnswer[i] = mid;
         }
         
         
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends