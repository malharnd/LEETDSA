// Kahn's Algo to perform Topological sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // create adj list
        unordered_map< int , list<int>> adj;
        for(int i = 0; i< prerequisites.size() ;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
        }
        
        // creating in degree tracking
        vector<int>indegree(numCourses);
        for(auto i: adj){
            for(auto j: i.second){
                indegree[j] ++;
            }
        }
        queue<int> q;
        // Checking for zero indegree
        for(int i = 0;  i< indegree.size() ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // BFS
        vector<int> ans;
        
        while(!q.empty()){
            int front = q.front();
            
            q.pop();
            ans.push_back(front);
            
            for(auto i: adj[front]){
                indegree[i] --;
                
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        if(ans.size()!= numCourses){
            return {};
        }

        return ans;
        
    }
};