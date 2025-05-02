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
    bool b(TreeNode* root,int num){
        if( root == NULL) return true;
        if( root->val != num)  return false;
        return (b(root->left,num) && b(root->right,num));
    }
    bool isUnivalTree(TreeNode* root) {
        int num = root->val;
        return b(root,num);
    }
};
