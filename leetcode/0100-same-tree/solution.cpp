class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == NULL && q == NULL) return true;
        else if( p == NULL || q == NULL) return false;
        if( p->val != q->val) return false;
        bool b = isSameTree(p->left,q->left);
        bool c = isSameTree(p->right,q->right);
        if( b == true && c == true) return true;
        return false;
    }
};
