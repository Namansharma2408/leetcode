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
    void insert(TreeNode* root , int val){
        if( root == NULL) return;
        if(root->val > val){
            if(root->left != NULL){
                insert( root->left , val );
            }
            else{
                TreeNode* a = new TreeNode(val);
                root->left = a;
            }
        }
        else {
            if(root->right != NULL){
                insert( root->right , val );
            }
            else{
                TreeNode* a = new TreeNode(val);
                root->right = a;
            }
        }
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if( root == NULL){
            TreeNode* a = new TreeNode(val);
            return a;
        }
        insert(root,val);
        return root;
    }
};
