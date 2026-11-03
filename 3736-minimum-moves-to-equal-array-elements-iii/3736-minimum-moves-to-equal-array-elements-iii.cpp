class Solution {
public:
    int minMoves(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int n = nums.size();
        int moves = 0;
        int maxi = *std::max_element(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            int diff = maxi - nums[i];
            moves += diff;
        }

        return moves;
    }
};