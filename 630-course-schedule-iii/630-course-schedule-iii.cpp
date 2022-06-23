class Solution {
public:
    bool static compare(vector<int>a, vector<int>b){
        
        if(a[1] == b[1])
            return a[0] <  b[0];
        
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(),compare);
        
        priority_queue<int> pq;
        int sum =0;
        
//         for(int i=0;i<n;i++)
//         {
//              if(courses[0][i] <= courses[i][1])
//              {
//                   if(courses[0][i]+time <= courses[i][1])
//                   {
//                        time+= courses[0][i];
//                       p.push(courses[0][i]);
//                   }
//              }
//             else
//             {
//                 if(courses[0][i] < p.top())
//                 {  
//                     time -= p.top();
//                      p.pop();
                    
//                     p.push(courses[0][i]);
//                     time += courses[0][i];
//                 }
//             }
//         }
//         return p.size();
        
        for(auto it : courses)
        {
             sum += it[0];
            pq.push(it[0]);
            
            if(sum > it[1])
            {
                sum-= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};