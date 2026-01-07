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
public:
    int Mod = 1e9 + 7;
    long long treeSum(TreeNode* root, long long& maxi, long long total) {
        if (!root)
            return 0;
        long long left = treeSum(root->left, maxi, total);
        long long right = treeSum(root->right, maxi, total);
        long long sum = root->val + left + right;
        maxi = max(maxi, sum * (total - sum));
        return sum;
    }
    int maxProduct(TreeNode* root) {
        long long dummy = 0;
        long long totalSum = treeSum(root,dummy,0);
        long long maxi = 0;
        treeSum(root, maxi, totalSum);

        return (int)(maxi%(long long)(1e9+7));
    }
};
