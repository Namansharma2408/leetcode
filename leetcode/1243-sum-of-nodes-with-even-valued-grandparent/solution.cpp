class Solution {
public:
    void sum(TreeNode* root,int &s){
        if( root == NULL) return;
        if((root->val)%2 == 0){
            if(root->left && root->left->left) s += root->left->left->val;
            if(root->left && root->left->right) s += root->left->right->val;
            if(root->right && root->right->left) s += root->right->left->val;
            if(root->right && root->right->right) s += root->right->right->val;
        }
        sum(root->left,s);
        sum(root->right,s);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        sum(root,ans);
        return ans;
    }
};
