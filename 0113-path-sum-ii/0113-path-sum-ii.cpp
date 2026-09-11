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

    vector<vector<int>> res;
    vector<int> path;
    void helper(TreeNode* root, int sum, int target){
        if(root == null){
            return;
        }

        sum = sum+root->val;
        path.push_back(root->val);

        if(root->left == null and root->right == null){
            if(sum == target){
                res.push_back(path);
                path.pop_back();
                return;
            }
        }
        helper(root->left, sum, target);
        helper(root->right, sum, target);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        helper(root, 0, target);
        return res;
    }
};