/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
//Preorder
void traverseleft(TreeNode<int> * root, vector<int> &ans){
    if((root == NULL ) || (root -> left == NULL && root -> right == NULL )){
        return;
    }

    ans.push_back(root -> data);

    if(root-> left){
        traverseleft(root -> left, ans);
    }
    else{
        traverseleft(root -> right, ans);
    }

}

void traverseleaf(TreeNode<int> * root, vector<int> &ans){

    if(root == NULL){
        return;
    }

    if(root -> left == NULL && root -> right == NULL ){
        ans.push_back(root -> data);
        return;
    }

    traverseleaf(root -> left,  ans);
    traverseleaf(root -> right, ans);
}

//Postorder
void traverseright(TreeNode<int> * root, vector<int> &ans){
    if((root == NULL ) || (root -> left == NULL && root -> right == NULL )){
        return;
    }

    if(root-> right){
        traverseright(root -> right, ans);
    }
    else{
        traverseright(root -> left, ans);
    }

    ans.push_back(root -> data);
}




vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
	if(root == NULL){
        return ans;
    }

    ans.push_back(root -> data);

    // Traverse Left side
    traverseleft(root -> left, ans);

    // Traverse leaf left side
    traverseleaf(root -> left, ans);

    // Traverse leaf right side
    traverseleaf(root -> right, ans);

    // Traverse right side
    traverseright(root -> right, ans);


    // return ans

    return ans;
}
