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
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        // since the array is sorted, we can take the middle value and use as root, ensuring that each side has same number of elements (+-1)
        TreeNode* root = nullptr;
        findRoot(0, nums.size()-1, nums, root);
        return root;
    }
    // use a void function to save memory in the call stack
    // pass by reference will operate on the same object, so we pass the reference to the pointer of our root node
    void findRoot(int start, int end, vector<int> &nums, TreeNode* &root)
    {
        // repeatedly take the middle value as root for each subtree
        if (start > end)
            return;
        int idx = (end+start) / 2;
        root = new TreeNode(nums[idx]);
        findRoot(start, idx-1, nums, root->left);
        findRoot(idx+1, end, nums, root->right);
    }
};