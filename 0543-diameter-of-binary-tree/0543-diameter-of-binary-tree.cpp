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
    pair<int,int> getdia(TreeNode* root){
        // Base case
        if(root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = getdia(root -> left);
        pair<int,int> right = getdia(root -> right);
        
        int leftsub_dia = left.first;
        int rightsub_dia = right.first;
        
        int left_right_dia = left.second + right.second + 1;
        
        pair<int,int> ans;
        
        ans.first = max(leftsub_dia, max(rightsub_dia,left_right_dia));
        
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
        
        
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        pair<int,int> ans = getdia(root);
        return ans.first - 1;
        
    }
};