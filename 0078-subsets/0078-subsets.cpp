class Solution {
public:
    void returnSubset(vector<int>& nums, int n, int idx, vector<int>& tmp, vector<vector<int>>& ans){
        if(idx == n){
            ans.push_back(tmp);
            return;
        }

        //not taking the element 
        returnSubset(nums, n, idx+1, tmp, ans);


        //taking the element 
        tmp.push_back(nums[idx]);
        returnSubset(nums, n, idx+1, tmp,ans);
        tmp.pop_back();
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        vector<vector<int>> ans;

        returnSubset(nums, n, 0, tmp, ans);
        return ans;
    }
};