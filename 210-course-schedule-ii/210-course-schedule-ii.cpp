class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        vector<int>ans;
        
        for(auto it : prerequisites)
        {
             graph[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<n;i++)
        {
             for(auto it: graph[i])
             {
                  indegree[it]++;
             }
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
             if(indegree[i]== 0)
             {
                  q.push(i);
             }
        }
        
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            
            for(auto it : graph[top])
            {
                 indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if( ans.size() == n) return ans;
        
        ans.clear();
        return ans;
    }
};