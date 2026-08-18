class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        // Case 1: k == 1
        // Each element forms its own subarray. Find the max element with frequency 1.
        if (k == 1) {
            int ans = -1;
            for (auto& [val, count] : freq) {
                if (count == 1) {
                    ans = max(ans, val);
                }
            }
            return ans;
        }

        // Case 2: k == n
        // The whole array is the only subarray. The max element in the array is the answer.
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n
        // Only boundary elements (nums[0] and nums[n - 1]) can appear in exactly one subarray,
        // provided they occur only once in the entire array.
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};