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
private:
    TreeNode* solve(vector<int> preorder, int mini, int maxi, int &count){
        if(count >= preorder.size()){
            return NULL;
        }

        if(preorder[count] < mini || preorder[count] > maxi){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[count++]);

        root -> left = solve(preorder, mini, root -> val, count );
        root -> right = solve(preorder, root -> val, maxi, count );

        return root;


        
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int count = 0;
        int mini =  INT_MIN;
        int maxi =  INT_MAX;

        return solve( preorder, mini, maxi, count );
        
    }
};