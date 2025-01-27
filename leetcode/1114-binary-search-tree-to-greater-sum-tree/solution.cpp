class Solution {
public:
    void work(TreeNode* root,long long &add){
        if( root == NULL) return;
        work(root->right,add); 
        root->val += add;
        add = root->val;       
        work(root->left,add);
    }
    TreeNode* bstToGst(TreeNode* root) {
        long long sum = 0;
        work(root,sum);
        return root;
    }
};
