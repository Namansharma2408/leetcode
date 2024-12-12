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
    void minDiff(vector<int> &v , TreeNode* root){
        if( root == NULL) return;
        else if( root->left) minDiff(v,root->left);
        v.push_back(root->val);
        if( root->right) minDiff(v,root->right);
        else return;
    }
    int minDiffInBST(TreeNode* root) {
        if ( root == NULL) return 0;
        vector<int> v;
        minDiff(v,root);
        int n = v.size();
        int min = v[1] - v[0];
        for( int i = 1 ; i < n ; i++){
            if( min > v[i] - v[i-1]) min = v[i] - v[i-1];
        }
        return min;
    }
};
