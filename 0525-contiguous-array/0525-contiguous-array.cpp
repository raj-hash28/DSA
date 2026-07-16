class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0, one = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> f;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zero++;
            }
            else {
                one++;
            }
            int diff = zero - one;
            if(diff == 0){
                ans = max(ans, i+1);
                continue;
            }
            if(f.find(diff) == f.end()){
                f[diff] = i;
            }
            else{
                int index = f[diff];
                int length = i-index;
                ans = max(ans, length);
            }
        }
        return ans;
    }
};