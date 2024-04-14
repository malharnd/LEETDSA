class Solution {
private:

bool isCyclicDFS(int node, int parent,  unordered_map<int, list<int>> &adj, 
                        unordered_map<int, bool> &visited ){
                            visited[node] =true;

                            for(auto next: adj[node]){
                                if(!visited[next]){
                                    bool cycle = isCyclicDFS(next, node, adj, visited);
                                    if(cycle){
                                        return true;
                                    }
                                }
                                else if(next!=parent){
                                    return true;

                                }
                            }
                            return false;
                        }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;

        
        // Creating adj list
        unordered_map<int, list<int>> adj;

        for(int i = 0 ; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            unordered_map<int, bool> visited;
            if(isCyclicDFS(u, -1, adj, visited)){
                return {u,v};
                
            }
        }
        return {};
    }
        
};