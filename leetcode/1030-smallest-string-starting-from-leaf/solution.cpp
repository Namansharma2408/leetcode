class Solution {
public:
    void small( deque<char> &dq,string &mini,TreeNode* root){
        if( root != NULL && root->left == NULL && root->right == NULL){
            dq.push_front(root->val + 'a');
            string str(dq.begin(),dq.end());
            if( str < mini) mini = str;
            dq.pop_front();
            return;
        }
        if( root == NULL ) return;
        dq.push_front(root->val + 'a');
        small(dq,mini,root->left);
        small(dq,mini,root->right);
        dq.pop_front();
    }
    string smallestFromLeaf(TreeNode* root) {
        string mini(8500,'~');
        deque<char> dq;
        small(dq,mini,root);
        return mini;
    }
};
