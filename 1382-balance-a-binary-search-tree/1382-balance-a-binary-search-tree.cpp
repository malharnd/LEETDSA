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
    void makeinorder(TreeNode* root, vector<int>&inorder){
        if(root == NULL){
            return;
        }

        makeinorder(root -> left, inorder);
        inorder.push_back(root -> val);
        makeinorder(root -> right, inorder);
    }

    TreeNode* makebal(int start, int end, vector<int> inorder){
        if(start > end){
            return NULL;
        }
        int mid = (start + end)/2;

        TreeNode* root = new TreeNode(inorder[mid]);

        root -> left = makebal(start, mid-1, inorder);
        root -> right = makebal(mid+1, end, inorder);

        return root;


    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {

        vector<int> inorder;
        makeinorder(root, inorder);


        return makebal(0, inorder.size()-1 , inorder);


        
    }
};