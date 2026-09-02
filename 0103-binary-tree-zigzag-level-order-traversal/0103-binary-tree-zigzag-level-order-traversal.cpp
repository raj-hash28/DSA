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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        bool leftToRight = 1;

        if(root == NULL){
            return {};
        } 

        q.push(root);

        while(!q.empty()){
            int lvlsize = q.size();
            vector<int> tmp(lvlsize);
            int first_idx = 0;
            int last_idx = lvlsize - 1;

            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();
                
                if(leftToRight == 1){
                    tmp[first_idx] = t->val;
                    first_idx++;
                }
                else{
                    tmp[last_idx] = t->val;
                    last_idx--;
                }
                
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
            }
            leftToRight = 1 - leftToRight;
            res.push_back(tmp);
        }

        return res;
    }
};