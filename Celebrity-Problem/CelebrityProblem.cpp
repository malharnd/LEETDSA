
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        
        //pushing people into stack
        stack<int> stack;
        
        for(int i = 0 ; i<n;i++){
            stack.push(i);
        }
        
        while(stack.size() > 1){
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            
            if(M[a][b] == 1){
                stack.push(b);
            }
            else{
                stack.push(a);
            }
        }
        //potential celebrity 
        int ans = stack.top();
        
        //checking if the ans is actually a celebrity 
        bool rowcheck = false;
        int rowcount  = 0;
        
        for(int i = 0; i<n ;i++){
            if(M[ans][i] == 0 ){
                rowcount++;
            }
        }
        
        if(rowcount == n){
            rowcheck = true;
        }
        
        bool colcheck = false;
        int colcount  = 0;
        
        for(int i = 0; i<n ;i++){
            if(M[i][ans] == 1 ){
                colcount++;
            }
        }
        if(colcount == n-1){
            colcheck = true;
        }
        
        if(colcheck == true && rowcheck == true){
            return ans;
        }
        else{
            return -1;
        }
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}