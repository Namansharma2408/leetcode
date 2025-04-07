class Solution {
public:
    string fs(TreeNode* root){
        if( root == NULL) return "";
        string str = "";
        string ch = to_string(root->val);
        str = str + ch;
        if( root->left == NULL && root->right == NULL ) return str;
        if( root->left != NULL && root->right == NULL ) return (str + "(" + fs(root->left) + ")" );     
        str = str + '(' + fs(root->left) + ')' + '(' + fs(root->right) + ')';
        return str;
    }
    string tree2str(TreeNode* root) {
        string str = fs(root);
        return str;
    }
};
