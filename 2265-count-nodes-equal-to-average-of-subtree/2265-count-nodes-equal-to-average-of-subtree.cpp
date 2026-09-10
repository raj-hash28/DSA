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

    int helper(TreeNode* root){
        queue<TreeNode*> q;

        q.push(root);
        int sum = 0; int count = 0;

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();

            sum += t->val;
            count++;

            if(t->left != null) q.push(t->left);
            if(t->right != null) q.push(t->right);
        }

        int avg = sum/count;
        if(avg == root->val) {
            return 1;
        }
        return 0;
    }
    int averageOfSubtree(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        int ans = 0;

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            ans += helper(t);

            if(t->left != null) q.push(t->left);
            if(t->right != null) q.push(t->right);
        }

        return ans;
    
    }
};