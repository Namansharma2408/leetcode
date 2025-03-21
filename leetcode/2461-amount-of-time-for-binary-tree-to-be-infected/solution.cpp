class Solution {
public:
    TreeNode* f = NULL;
    void find(TreeNode* root , int start){
        if( root == NULL) return;
        if( root->val == start) f = root;
        find(root->left,start);
        find(root->right,start);
    }

    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent ){
        if( root == NULL) return;
        if( root->left ) parent[root->left] = root;
        if( root->right ) parent[root->right] = root;
        markParent(root->left,parent);
        markParent(root->right,parent);
    }
    int amountOfTime(TreeNode* root, int start) {
        // find the start
        find(root,start);
        TreeNode* first = f;
        // mark parents
        unordered_map<TreeNode*,TreeNode*> parent;
        markParent(root,parent);
        // make a set of infected ones
        unordered_set<TreeNode*> s;
        s.insert(first);
        // make queue for bfs
        queue<pair<TreeNode*,int>> q;
        q.push({first,0});
        // bfs
        int maxlevel = 0;
        while( !q.empty() ){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            int level = p.second;
            TreeNode* temp = p.first;
            maxlevel = max(maxlevel,level);
            if( temp->left != NULL){
                if(s.find(temp->left) == s.end()){
                    q.push({temp->left,level+1});
                    s.insert(temp->left);
                }
            }if( temp->right != NULL){
                if(s.find(temp->right) == s.end()){
                    q.push({temp->right,level+1});
                    s.insert(temp->right);
                }
            }if( parent.find(temp) != parent.end()){
                if(s.find(parent[temp]) == s.end()){
                    q.push({parent[temp],level+1});
                    s.insert(parent[temp]);
                }
            }
        }
        return maxlevel;
    }
};
