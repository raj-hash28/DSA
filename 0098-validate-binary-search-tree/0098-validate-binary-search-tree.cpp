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
    TreeNode* prev = null;
    bool ans = true;
    void helper(TreeNode* root){
        if(root == null){
            return;
        }

        helper(root->left);
        if(prev == null){
            prev = root;
        }
        else{
            if(root->val <= prev->val){
                ans = false;
            }
            prev = root;
        }
        helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};