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
    int findPosition(vector<int> inorder, int element, int n){
        for(int i=0;i<n;i++){
            if(inorder[i]==element)
            return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int> preorder, vector<int> inorder, int &preorderindex,
    int inorderstart,int inorderend, int size){
        if(preorderindex > size || inorderstart > inorderend ){
            return NULL;
        }

        int val = preorder[preorderindex++];

        TreeNode* root = new TreeNode(val);

        // int pos = nodeIndex[val];
        int pos = findPosition(inorder, val, size);


        root -> left = solve(preorder, inorder, preorderindex, inorderstart, pos-1, size);
        root -> right = solve(preorder, inorder, preorderindex, pos+1, inorderend,size);

        return root;

        
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int size = preorder.size();
        int preorderindex = 0;

        TreeNode* ans = solve(preorder, inorder, preorderindex, 0, 
        size-1, size);

        return ans;
        
    }
};