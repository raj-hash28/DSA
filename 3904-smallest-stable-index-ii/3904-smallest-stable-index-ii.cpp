class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> res(n, 0);
        res[n-1] = nums[n-1];
        ans[0] = nums[0];

        for(int i = 1; i < n; i++){
            ans[i] = max(ans[i-1], nums[i]);
        }

        for(int i = n-2; i >= 0; i--) {
            res[i] = min(res[i+1], nums[i]);
        }

        for(int i = 0; i< ans.size(); i++){
            if(ans[i] - res[i] <= k){
                return i;
            }
        }

        return -1;
    }
};