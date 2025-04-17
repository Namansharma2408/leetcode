/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void nodeAdd(TreeNode* root,int val,int depth,int currDepth){
        if( root == NULL || currDepth >= depth) return;
        if( currDepth == depth - 1){
            TreeNode* a = new TreeNode(val);
            TreeNode* b = new TreeNode(val);
            a->left = root->left;
            b->right = root->right;
            root->left = a;
            root->right = b;
        }
        nodeAdd(root->left,val,depth,currDepth+1);
        nodeAdd(root->right,val,depth,currDepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        nodeAdd(root,val,depth,1);
        if( depth == 1){
            TreeNode* a = new TreeNode(val);
            a->left = root;
            root = a;
        }
        return root;
    }
};
