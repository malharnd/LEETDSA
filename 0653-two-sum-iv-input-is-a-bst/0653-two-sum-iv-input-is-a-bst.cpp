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
int solve(vector<int> inorder, int k, int &count){
    int start = 0;
    int end = inorder.size() - 1;
    
    while(start < end){
        int sum = inorder[start] + inorder[end];
        cout << sum;

        if(sum == k){
            count ++;
        }
        if(sum > k){
            end --;
        }
        
        else{
            start ++;
        }

    }
    return count;
    
}
void inordertrav(TreeNode* root, int k, vector<int>& inorder){
    if(root == NULL){
        return;
    }
    inordertrav(root-> left, k, inorder);
    inorder.push_back(root -> val);
    inordertrav(root-> right, k, inorder);
}
public:
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> inorder;
        inordertrav( root,k, inorder);
        int count = 0;
        
        int ans = solve(inorder,k, count);
        // cout << ans;     
        if(ans >= 1){
            return true;
        }
        else{
        return false;
        }
        
    }
};