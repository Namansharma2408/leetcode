class Solution {
public:
    int maxDepth = -1;
    TreeNode* lca = nullptr;

    int dfs(TreeNode* root, int depth) {
        if (!root) return depth - 1;

        maxDepth = max(maxDepth, depth);

        int left = dfs(root->left, depth + 1);
        int right = dfs(root->right, depth + 1);

        if (left == maxDepth && right == maxDepth)
            lca = root;

        return max(left, right);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        return lca;
    }
};
