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
    void helper(TreeNode* root, TreeNode* p, TreeNode* q){
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);

        if(root == null) return;

        if(root == p or root == q){
            ans = root;
            return;
        }

        if(root->val < small){
            helper(root->right, p, q);
        }
        else if(root->val > large){
            helper(root->left, p, q);
        }
        else {
            ans = root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};