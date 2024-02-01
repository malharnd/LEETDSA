#include<iostream>
using namespace std;

class Solution{
    
    private:
    
    // checkig if its a possible move
    bool isPossible(int x, int y,vector<vector<int>> &visited, vector<vector<int>> &m , int n){
        if((x>=0 && x<=n-1) && (y>=0 && y<=n-1) && visited[x][y] == 0 && m[x][y] == 1 ){
            return true;
        }
        else{
            return false;
        }
        
    }
    void rat(int x, int y, vector<vector<int>> &visited,vector<vector<int>> &m, int n, string path, vector<string> &ans){
        //base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        // set visited value
        visited[x][y] = 1;

        //defining movement 
        // down
        int newx = x+1;
        int newy = y;
        if(isPossible(newx, newy, visited, m , n)){
            path.push_back('D');
            rat(newx, newy , visited, m , n , path, ans);
            path.pop_back();
        }
        
        // left
        newx = x;
        newy = y-1;
        if(isPossible(newx, newy, visited, m , n)){
            path.push_back('L');
            rat(newx, newy , visited, m , n , path, ans);
            path.pop_back();
        }
        
        // right
        newx = x;
        newy = y+1;
        if(isPossible(newx, newy, visited, m , n)){
            path.push_back('R');
            rat(newx, newy , visited, m , n , path, ans);
            path.pop_back();
        }
        
        
        // up
        newx = x-1;
        newy = y;
        if(isPossible(newx, newy, visited, m , n)){
            path.push_back('U');
            rat(newx, newy , visited, m , n , path, ans);
            path.pop_back();
        }
        
        
        //set visited back to 0 ( back tracking)
        visited[x][y] = 0;

        
        
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
    
        // Your code goes here
        vector<string> ans;
        int srcx = 0;
        int srcy = 0;
        
        if (m[0][0] == 0) {
            return ans;
        }
        
        vector<vector<int>> visited = m;
        
        //initialise visited with 0
        
        for(int i  = 0 ; i < n; i++ ){
            for(int j = 0; j < n; j++){
                visited[i][j] = 0;
            }
        }
        
        string path = "";
        
        rat(srcx, srcy, visited, m , n , path, ans);
        sort(ans.begin(), ans.end());
        return ans;
        
        
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends