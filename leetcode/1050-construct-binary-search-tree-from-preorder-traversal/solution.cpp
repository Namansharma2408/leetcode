class Solution {
public:
    void insert(TreeNode* root , int val){
        if( root == NULL) return;
        if(root->val > val){
            if(root->left != NULL) insert( root->left , val );
            else root->left = new TreeNode(val);
        }
        else {
            if(root->right != NULL) insert( root->right , val );
            else root->right = new TreeNode(val);
        }
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if( root == NULL) return new TreeNode(val);
        insert(root,val);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int n = preorder.size();
        for( int i = 1 ; i < n ; i++) root = insertIntoBST( root, preorder[i]);           
        return root;
    }
};
