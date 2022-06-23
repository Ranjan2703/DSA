class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        
        for(auto it : pre)
        {
             graph[it[1]].push_back(it[0]);
             
        }
        
       for(int i=0;i<numCourses;i++)
       {
            for(auto it : graph[i])
            {
                 indegree[it]++;
            }
       }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
             if(indegree[i] == 0)
                 q.push(i);
        }
        
        int count =0;
        
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            count++;
            
            for( auto node : graph[top])
            {
                 indegree[node]--;
                
                if( indegree[node] == 0)
                    q.push(node);
            }
            
        }
        
        if (count == numCourses) return true;
        
        
        return false;
        
    }
};