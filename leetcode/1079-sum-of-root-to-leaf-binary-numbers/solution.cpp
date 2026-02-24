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
    void sum(TreeNode* root, int &curr, int &ans){
        if( root == NULL ) return;
        if( root->left == NULL && root->right == NULL ){
            curr *= 2;
            curr += root->val;
            ans += curr;
            curr /= 2;
            return;
        }
        curr *= 2;
        curr += root->val;
        sum(root->left,curr,ans);
        sum(root->right,curr,ans);
        curr /= 2;
    }
    int sumRootToLeaf(TreeNode* root) {
        int curr = 0;
        int ans = 0;
        sum(root,curr,ans);
        return ans;
    }
};
