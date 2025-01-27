class Solution {
public:
    TreeNode* buildTree(int start,int end, vector<int>& nums){
        if( start > end) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(start,mid-1,nums);
        root->right = buildTree(mid+1,end,nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = buildTree(0,n-1,nums);
        return root;
    }
};
