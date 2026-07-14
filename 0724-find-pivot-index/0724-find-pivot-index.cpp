class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int i;
        for(i = 0; i < n; i++)
        sum = sum + nums[i];

        int left = 0;
        for(int i = 0; i < n; i++){
            int right = sum - nums[i] - left;

            if(left == right)
            return i;
            
            left = left + nums[i];
        }
        return -1;
    }
};