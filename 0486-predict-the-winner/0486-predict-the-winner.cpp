class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] stores the maximum net score a player can achieve from nums[i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: only one element left
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        // Fill DP table for subarrays of length 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        // Player 1 wins if the net score is >= 0
        return dp[0][n - 1] >= 0;
    }
};