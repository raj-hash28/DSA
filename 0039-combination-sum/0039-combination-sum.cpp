class Solution {
public:
    void helper(vector<int>& candidates, int n, int idx, vector<int>& diary, vector<vector<int>>& res, int target, int sum){
        if(idx == n){
            if(sum == target){
                res.push_back(diary);
            }
            return;
        }

        //choice_1 Ni lena hai
        helper(candidates, n, idx+1, diary, res, target, sum);

        //choice_2 lena hai 
        if(sum + candidates[idx] <= target){
            diary.push_back(candidates[idx]);
            sum = sum + candidates[idx];
            helper(candidates, n, idx, diary, res, target, sum);
            diary.pop_back();
            sum = sum - candidates[idx];
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> diary;
        vector<vector<int>> res;
        int n = candidates.size();
        int sum = 0;

        helper(candidates, n, 0, diary, res, target, sum);

        return res;
    }
};