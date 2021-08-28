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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) 
            return NULL;
        if(preorder.size() == 1)
            return new TreeNode(preorder[0]);
        
        int index;
        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                index = i;
                break;
            }                
        }
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+index+1);
        vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightPreorder(preorder.begin()+index+1, preorder.end());
        vector<int> rightInorder(inorder.begin()+index+1, inorder.end());
        return new TreeNode(preorder[0], buildTree(leftPreorder, leftInorder), buildTree(rightPreorder, rightInorder));   
    }
};