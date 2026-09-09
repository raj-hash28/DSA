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
    
    vector<int> tmp;
    void helper(TreeNode* root, int k){
        if(root == null){
            return;
        }

        helper(root->left, k);
        tmp.push_back(root->val);
        helper(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        helper(root, k);
        int n = tmp.size();
        int i = 0; 
        int j = n-1;

        while(i < j){
            int sum = tmp[i] + tmp[j];

            if(sum == k){
                return true;
            }

            if(sum < k){
                i++;
            }
            else{
                j--;
            }
        }

        return false;
    }
};