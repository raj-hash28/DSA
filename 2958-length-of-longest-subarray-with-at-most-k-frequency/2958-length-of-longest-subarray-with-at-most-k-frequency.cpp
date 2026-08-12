class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        int low = 0;
        int high = 0;
        int n = nums.size();
        int res = 0;

        for(high = 0; high < n; high++){
            f[nums[high]]++;

            while(f[nums[high]] > k){
                f[nums[low]]--;
                low++;
            }
            
            int length = high-low+1;
            res = max(res, length);
        }
        return res;
    }
};