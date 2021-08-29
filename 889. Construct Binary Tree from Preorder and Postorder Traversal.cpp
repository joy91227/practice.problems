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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(postorder.size() == 0) 
            return NULL;
        if(postorder.size() == 1)
            return new TreeNode(postorder[0]);
        
        int leftChild; 
        for (int i=0; i<postorder.size(); i++) {
            if (postorder[i] == preorder[1]) {
                leftChild = i;
                break;
            }                
        }
        vector<int> leftPostorder(postorder.begin(), postorder.begin()+leftChild);
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+leftChild+1);
        vector<int> rightPostorder(postorder.begin()+leftChild+1, postorder.end()-1);
        vector<int> rightPreorder(preorder.begin()+leftChild+1, preorder.end());
        return new TreeNode(preorder[0], buildTree(leftPreorder, leftPostorder), buildTree(rightPreorder, rightPostorder));   
    }
};