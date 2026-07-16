class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, result = 0;
        unordered_map<int, int> f;
        f[0] = 1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            sum += nums[i];
            int remainder = sum % k;
            if(remainder < 0)
            remainder = remainder + k;

            result = result + f[remainder];
            f[remainder]++;
        }
        return result;
    }
};