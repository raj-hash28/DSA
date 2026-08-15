class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int resultXor = 0;
        bool allzero = true;

        for(int& x : nums){
            resultXor = (resultXor ^ x);

            if(x != 0){
                allzero = false;
            }
        }

        if(allzero){
            return 0;
        }

        return (resultXor == 0) ? n-1 : n;
    }
};