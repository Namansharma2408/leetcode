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
    unordered_map<int,int> mp;
    void levelSum(TreeNode* root, int &currLevel){
        if( root == NULL ) return;
        mp[currLevel] += root->val;
        currLevel += 1;
        levelSum(root->left,currLevel);
        levelSum(root->right,currLevel);
        currLevel -= 1;

    }
    int maxLevelSum(TreeNode* root) {
        int currLevel = 1;
        levelSum(root,currLevel);
        int maxi = 1;
        for( auto p : mp ){
            if( p.second >= mp[maxi] ) maxi = p.first;
        }
        return maxi;
    }
};
