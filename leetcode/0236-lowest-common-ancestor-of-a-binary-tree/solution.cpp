class Solution {
public:
    bool existInTree(TreeNode* root,TreeNode* target){
        if( root == NULL) return false;
        if( root == target) return true;
        return existInTree(root->left,target) || existInTree(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == p || root == q) return root;
        if(existInTree(root->left,p) && existInTree(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else if(existInTree(root->right,p) && existInTree(root->right,q) ) return lowestCommonAncestor(root->right,p,q);
        return root;
        
        
        
    }
};
