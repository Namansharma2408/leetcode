/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    unordered_map<int, long long> mp;
    void levelSum(TreeNode* root, int& currLevel) {
        if (root == NULL)
            return;
        mp[currLevel] += (long long)root->val;
        currLevel += 1;
        levelSum(root->left, currLevel);
        levelSum(root->right, currLevel);
        currLevel -= 1;
    }

public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int currLevel = 1;
        levelSum(root, currLevel);
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> pq;
        for( auto p : mp){
            pq.push({p.second,p.first});
            if( pq.size() > k ) pq.pop();
        }
        if( pq.size() < k ) return -1;
        return pq.top().first;
    }
};
