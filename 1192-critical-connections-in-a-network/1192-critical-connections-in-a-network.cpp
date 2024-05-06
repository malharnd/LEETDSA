class Solution {
private:
int timer = 0;
    
private:
    void dfs(int node, int parent, vector<int> &visited, 
             unordered_map<int,list<int>> &adj, int discovery[],int low[] ,vector<vector<int>> &ans ){
        visited[node] = 1;
        discovery[node] = low[node] = timer;
        timer ++;
        
        for(auto it: adj[node]){

            if(it == parent) continue;
            
            if(visited[it] == 0){
                dfs(it, node, visited,adj,discovery,low, ans);
                //out of dfs --> check low 
                low[node] = min(low[node], low[it]);
                
                // Hypothetically removing edge
                if(low[it] > discovery[node]){
                    ans.push_back({node,it});
                }
            }
            // Node is already visited that mean it can be accressed before the current node 
            // Hence we just check for the lowest since it is a adj node and not a parent
            
            else{
                low[node] = min(low[node], low[it]);
            }
            
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>> adj;
        for(int i = 0; i<connections.size() ;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        vector<int> visited(n,0);
        int discoverytime[n];
        int low[n];
        vector<vector<int>> bridges;
        
        dfs(0, -1, visited,adj,discoverytime,low, bridges);
        
        return bridges;
        
        
        
    }
};