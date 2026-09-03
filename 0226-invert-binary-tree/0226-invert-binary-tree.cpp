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
    #define null NULL

    void helper(TreeNode* root){
        if(root == null)
            return;

        swap(root->left, root->right);

        helper(root->left);
        helper(root->right);

        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};