class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum = 0;
        for(int num : nums){
            total_sum += num;
        }

        int target = total_sum - x;
        if(target < 0 ) return -1;
        if(target == 0) return nums.size();

        int max_len = -1;
        int curr_sum = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            curr_sum += nums[right];

            while(curr_sum > target && left <= right){
                curr_sum -= nums[left];
                left++;
            }

            if(curr_sum == target){
                max_len = std::max(max_len, right - left + 1);
            }
        }

        return max_len == -1 ? -1 : nums.size() - max_len;
    }
};