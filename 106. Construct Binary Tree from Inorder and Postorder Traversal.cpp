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

// TODO improve runtime
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) 
            return NULL;
        if(postorder.size() == 1)
            return new TreeNode(postorder[0]);
        
        int index; //root
        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i] == *postorder.rbegin()) {
                index = i;
                break;
            }                
        }
        vector<int> leftPostorder(postorder.begin(), postorder.begin()+index);
        vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightPostorder(postorder.begin()+index, postorder.end()-1);
        vector<int> rightInorder(inorder.begin()+index+1, inorder.end());
        return new TreeNode(*postorder.rbegin(), buildTree(leftInorder, leftPostorder), buildTree(rightInorder, rightPostorder));   
    }
};