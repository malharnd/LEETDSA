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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftright = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> temparr(size);
            for(int i = 0 ; i< size; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(leftright){
                    temparr[i] = temp -> val; 
                }
                else{
                    temparr[size - i -1] = temp -> val; 
                }

                if(temp -> left){
                    q.push(temp -> left);
                }

                if(temp -> right){
                    q.push(temp -> right);
                }

            }
            leftright = !leftright;

            result.push_back(temparr);
        }

        return result;

        
    }
};