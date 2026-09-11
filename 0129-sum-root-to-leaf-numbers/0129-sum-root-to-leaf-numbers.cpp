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

    int res = 0;
    void helper(TreeNode* root, int sum){
        if(root == null){
            return;
        }

        sum = sum*10 + root->val;

        if(root->left == null and root->right == null){
            res += sum;
        }
        else{
            helper(root->left, sum);
            helper(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return res;
    }
};