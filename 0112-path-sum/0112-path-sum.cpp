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
    
    bool res = false;

    void helper(TreeNode* root, int sum, int target){
        if(root == null) return;

        sum += root->val;

        if(root->left == null and root->right == null){
            if(sum == target){
                res = true;
                return;
            }
        }
        else{
            helper(root->left, sum, target);
            helper(root->right, sum, target);
        }
    }
    bool hasPathSum(TreeNode* root, int target) {
        int sum = 0;
        helper(root, sum, target);
        return res;
    }
};