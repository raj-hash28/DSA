class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int minEle = INT_MAX;
            int maxEle = INT_MIN;

            for(int j = 0; j <= i; j++){
                maxEle = max(maxEle, nums[j]);
            }

            for(int j = i; j < n; j++){
                minEle = min(minEle, nums[j]);
            }

            if(maxEle - minEle <= k){
                return i;
            }
        }

        return -1;
    }
};