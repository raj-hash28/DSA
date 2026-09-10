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

    int sum = 0; 
    int count = 0;

    void helper(TreeNode* root){
        if(root == null) return;

        sum += root->val;
        count++;

        helper(root->left);
        helper(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> tmp;

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            helper(t);
            int avg = sum/count;

            if(avg == t->val){
                ans++;
            }

            if(t->left != null) q.push(t->left);
            if(t->right != null) q.push(t->right);

            sum = 0; 
            count = 0;
        }

        return ans;
    }
};