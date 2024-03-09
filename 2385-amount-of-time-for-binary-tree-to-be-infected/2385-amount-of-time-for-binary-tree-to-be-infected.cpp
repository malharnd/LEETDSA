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
 #include<map>
class Solution {
private:
    TreeNode* createmap(TreeNode* root, int start,  map<TreeNode*,TreeNode*> &parentmap ){
        
        TreeNode* target = NULL;
        
        queue<TreeNode*> q;
        
        q.push(root);
        parentmap[root] = NULL;
        
        
        while(!q.empty()){
            TreeNode*temp = q.front();
            q.pop();
            
            if(temp -> val == start){
                target = temp;
            }
            
            if(temp -> left){
                parentmap[temp -> left] = temp;
                q.push(temp -> left);
            }
            if(temp -> right){
                parentmap[temp -> right] = temp;
                q.push(temp -> right);
            }
        }
        
        return target;
        
    }
    
    void infect(TreeNode* target, map<TreeNode*,TreeNode*> &parentmap, int &ans){
        
        bool flag = false;
        map <TreeNode*,bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target] = true;
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();
                
                if(front -> left && !visited[front->left] ){
                    flag = true;
                    q.push(front->left);
                    visited[front -> left] = true;
                }
                
                if(front -> right && !visited[front->right] ){
                    flag = true;
                    q.push(front->right);
                    visited[front -> right] = true;
                }
                
                if(parentmap[front] && !visited[parentmap[front]]){
                    flag = true;
                    q.push(parentmap[front]);
                    visited[parentmap[front]] = true;
                }
            }
            
            if(flag){
                ans ++;
            }
        }
        
        

    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans  = 0;
        
        map<TreeNode*,TreeNode*> parentmap;
        
        TreeNode* target = createmap(root,start,parentmap);
        
        infect(target,parentmap,ans);

        if(ans == 0){
            return ans;
        }
        else{
            return ans-1;
        }
        

        
    }
};