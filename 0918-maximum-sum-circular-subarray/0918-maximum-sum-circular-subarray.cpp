class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;

        int curr_max = 0;
        int best_max = nums[0];

        int curr_min = 0;
        int best_min = nums[0];
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            total_sum = total_sum + nums[i];

            curr_max = max(nums[i], curr_max + nums[i]);
            best_max = max(best_max, curr_max);

            curr_min = min(nums[i], curr_min + nums[i]);
            best_min = min(best_min, curr_min);
        }
        if(best_max < 0)
            return best_max;
        
        return max(best_max, total_sum - best_min);
    }
};