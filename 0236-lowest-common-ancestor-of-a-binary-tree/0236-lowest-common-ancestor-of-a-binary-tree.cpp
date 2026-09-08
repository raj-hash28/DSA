/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    #define null NULL


    TreeNode* ans = null;
    int helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == null){
            return 0;
        }

        int left = helper(root->left, p, q);
        int right = helper(root->right, p, q);
        int self = 0;

        if(root == p or root == q){
            self = 1;
        }

        int total = left+self+right;

        if(total == 2 and ans == null){
            ans = root;
        }

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};