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

    bool helper(TreeNode* root1, TreeNode* root2){
        if(root1 == null and root2 == null){
            return true;
        }

        if(root1 == null or root2 == null){
            return false;
        }

        if(root1->val != root2->val){
            return false;
        }

        bool r1 = helper(root1->left, root2->right);
        bool r2 = helper(root1->right, root2->left);

        if(r1 == true and r2 == true){
            return true;
        }

        else return false;
    }

    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};