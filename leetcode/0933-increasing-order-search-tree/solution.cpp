class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if( root == NULL ) return NULL;
        TreeNode* l = increasingBST(root->left);
        TreeNode* r = increasingBST(root->right);
        TreeNode* temp = l;
        while( temp != NULL && temp->right != NULL ){
            temp = temp->right;
        }
        root->left = NULL;
        if(temp != NULL ) temp->right = root;
        root->right = r;
        if( l != NULL )return l;
        return root;
    }
};
