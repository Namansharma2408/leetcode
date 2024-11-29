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
    void stackPush(TreeNode* root,stack<TreeNode*> &st ){
        if( root== NULL) return;
        st.push(root);
        if(root->left) stackPush(root->left,st);
        if(root->right)stackPush(root->right,st);
        return;
    }
    void flatten(TreeNode* root) {
        if( root == NULL) return;
        if( root->left == NULL && root->right == NULL) return;
        stack<TreeNode*> st;
        stackPush(root,st);
        root = st.top();
        st.pop();
        while(!st.empty()){
            st.top()->right = root;
            st.top()->left = NULL;
            root = st.top();
            st.pop();
        }
        root->left = NULL;
        return;
    }
};
