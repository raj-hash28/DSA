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

    void helper(TreeNode* root, vector<TreeNode*>& res){
        if(root == null){
            return;
        }

        helper(root->left, res);
        res.push_back(root);
        helper(root->right, res);

        return;
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> res;
        helper(root, res);
        int galat = 0;
        TreeNode* g1_first = null;
        TreeNode* g1_second = null;
        TreeNode* g2_first = null;
        TreeNode* g2_second = null;

        for(int i = 0; i<res.size()-1; i++){
            if(res[i]->val > res[i+1]->val){
                if(galat == 0){
                    g1_first = res[i];
                    g1_second = res[i+1];
                    galat++;
                }
                else{
                    g2_first = res[i];
                    g2_second = res[i+1];
                    galat++;
                }
            }
        }

        if(galat == 1){
            swap(g1_first->val, g1_second->val);
        }

        if(galat == 2){
            swap(g1_first->val, g2_second->val);
        }
    }
};