class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        long long res = 0;
        int count = 0;
        int maxE = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        while(high < n){
            if(nums[high] == maxE){
                count++;
            }

            while(count >= k){
                res = res + n-high;

                if(nums[low] == maxE){
                    count--;
                }
                low++;
            }
            high++;
        }
        return res;
    }
};