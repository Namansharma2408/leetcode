class Solution {
public:
    int height(TreeNode* root){
        if( root == NULL) return 0;
        return 1+max(height(root->left),height(root->right));

    }
    void helper(TreeNode* root,int &maxDia){
        if( root == NULL) return ;
        int dia = height(root->left) + height(root->right);
        maxDia = max(maxDia,dia);
        helper(root->left,maxDia);
        helper(root->right,maxDia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root,maxDia);
        return maxDia;
    }
};
