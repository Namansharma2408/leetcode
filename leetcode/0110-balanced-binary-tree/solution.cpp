class Solution {
public:
    int height(TreeNode* root){
        if( root == NULL ) return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        if( h1 == -1 || h2 == -1 ) return -1;
        if( abs(h1-h2) > 1 ) return -1;
        return 1+max(h1,h2);
    }
    bool isBalanced(TreeNode* root) {
        if( root == NULL ) return true;
        if(height(root) != -1) return true;
        return false;
    }
};
