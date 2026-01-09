/**
 * Definition for a binary tree node.
 * vuct TreeNode {
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
    int height(TreeNode* root, vector<int>& curr, vector<int>& v) {
        if (root == NULL) {
            if (curr.size() > v.size()) {
                v.clear();
                v.resize(curr.size());
                for (int i = 0; i < curr.size(); i++) {
                    v[i] = curr[i];
                }
            }
            return 0;
        }
        curr.push_back(root->val);
        int h = max(height(root->left, curr, v), height(root->right, curr, v));
        curr.pop_back();
        return 1 + h;
    }
    vector<int> fun(vector<int>& v, vector<int>& curr) {
        int n = min(v.size(), curr.size());
        vector<int> s;

        for (int i = 0; i < n; i++) {
            if (v[i] == curr[i])
                s.push_back(v[i]);
            else
                break;
        }
        return s;
    }
    void Finding(TreeNode* root, vector<int>& v, vector<int>& curr, int& level,
                 int& h) {
        if (root == NULL) {
            if (level == h + 1) {
                v = fun(v, curr);
            }
            return;
        }
        curr.push_back(root->val);
        level += 1;
        Finding(root->left, v, curr, level, h);
        Finding(root->right, v, curr, level, h);
        level -= 1;
        curr.pop_back();
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<int> v;
        vector<int> curr;
        int level = 1;
        int h = height(root, curr, v);
        curr.clear();
        Finding(root, v, curr, level, h);
        int n = v.size();
        int i = 1;
        while (i < n && root != NULL) {
            if (root->left && root->left->val == v[i]) {
                root = root->left;
            }
            else if (root->right && root->right->val == v[i]) {
                root = root->right;
            } else {
                break;
            }
            i++;
        }
        return root;
    }
};
