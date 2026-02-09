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
    void inTraversal(TreeNode *root, vector<int> &inorder){
        if( root == NULL ) return;
        inTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inTraversal(root->right, inorder);
    }
    TreeNode *constructBBST(vector<int> &inorder, int lo, int hi){
        if( lo > hi ) return NULL;

        int mid = (lo + hi)/2;
        TreeNode *curr = new TreeNode(inorder[mid]);
        curr->left = constructBBST(inorder,lo,mid-1);
        curr->right = constructBBST(inorder,mid+1,hi);
        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if( root == NULL ) return NULL;
        vector<int> inorder;
        inTraversal(root,inorder);
        return constructBBST(inorder,0,inorder.size()-1);
    }
};
