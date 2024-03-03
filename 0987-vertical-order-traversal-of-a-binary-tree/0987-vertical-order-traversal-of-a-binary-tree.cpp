/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // map<int, map<int,vector<int>>> nodes;
         map<int, vector<pair<int, int>>> nodes;
        // Horizontal Distance and Level
        queue <pair<TreeNode*, pair<int,int>>> q;
        vector<vector<int>> ans;
        
        if(root == NULL){
            return ans;
        }
        
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()){
            pair<TreeNode*, pair<int,int>> temp = q.front();
            TreeNode* frontNode =  temp.first;
            int HD = temp.second.first;
            int level = temp.second.second;
            q.pop();

            nodes[HD].push_back(make_pair(level, frontNode -> val));
            
            if(frontNode -> left ){
                q.push(make_pair(frontNode -> left, make_pair(HD-1,level+1)));
            }
            
            if(frontNode -> right ){
                q.push(make_pair(frontNode -> right, make_pair(HD+1,level+1)));
            }
               
        }
        
        
        
        for(auto i: nodes){
             auto& nodeValues = i.second;
            sort(nodeValues.begin(),nodeValues.end());
            vector<int> column;
            for(auto& node: nodeValues){
                column.push_back(node.second);
            }
            ans.push_back(column);
        }
        return ans;
    }
};