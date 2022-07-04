// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src, vector<int> &v, vector<int> &order ,vector<int> adj[])
    {  
        v[src] = 1;
        order[src] =1;
        
        for(auto it  : adj[src])
        {
             if(!v[it])
             {
                  if(dfs(it, v,order,adj)) return true;
             }
             else if(order[it]) return true;
        }
        order[src] =0;
        return false;
         
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> v(V,0);
        vector<int> order(V,0);
       
       for(int i=0;i<V;i++)
       {
            if(!v[i])
            {
                if(dfs(i,v,order,adj)) return true;
            }
       }
       return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends