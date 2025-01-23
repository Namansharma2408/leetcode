class Solution {
public:
    TreeNode* build(vector<int>& pre, vector<int>& in,int prelo,int prehi,int inlo , int inhi){
        if( prelo > prehi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if( prelo == prehi) return root;
        int i = inlo;
        while( i <= inhi){
            if( in[i] == pre[prelo]) break;
            i++;
        }
        int leftcount = i - inlo;
        int rightcount = inhi - i;
        root->left = build(pre,in,prelo + 1,prelo + leftcount,inlo,i-1);
        root->right = build(pre,in,prelo + leftcount + 1,prehi,i+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return build(pre,in,0,n-1,0,n-1);
    }
};
