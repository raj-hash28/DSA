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
    
    void helper(TreeNode* root, vector<int>& res){
        if(root == null){
            return;
        }

        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        helper(root, res);

        for(int i = 0; i < res.size()-1; i++){
            if(res[i] >= res[i+1]){
                return false;
            }
        }
        return true;
    }
};