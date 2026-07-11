class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int bestEnding_max = nums[0];
        int bestEnding_min = nums[0];
        int ans = abs(nums[0]);
        int n = nums.size();

        for(int i = 1; i < n; i++){
            int v1 = bestEnding_max + nums[i];
            int v2 = bestEnding_min + nums[i];
            int v3 = nums[i];
            bestEnding_max = max(v3, max(v1, v2));
            bestEnding_min = min(v3, min(v1, v2));
            ans = max(ans, max(abs(bestEnding_max), abs(bestEnding_min)));
        }
        return ans;
    }
};