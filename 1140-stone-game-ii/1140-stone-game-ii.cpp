class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffixsum(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            suffixsum[i] = suffixsum[i+1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        return solve(0, 1, piles, suffixsum, dp, n);
    }

    private:
        int solve(int i, int M, const vector<int>& piles, const vector<int>& suffixsum, vector<vector<int>>& dp, int n){
            
            if(i >= n) return 0;

            if(i+2*M >= n){
                return suffixsum[i];
            }

            if(dp[i][M] != 0){
                return dp[i][M];
            }

            int maxStones = 0;

            for(int X = 1; X <= 2*M; X++){
                int nextM = max(M, X);

                int CurrentStones = suffixsum[i] - solve(i+X, nextM, piles, suffixsum, dp, n);

                maxStones = max(maxStones, CurrentStones);
            }

            return dp[i][M] = maxStones;
        }
};