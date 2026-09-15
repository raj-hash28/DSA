class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n));

        for(int i = 1; i <= n; i++){
            for(int left = 0; left+i <= n; left++){
                int right = left + i -1;
                isPalindrome[left][right] = s[left] == s[right] && (i <= 2 || isPalindrome[left+1][right-1]);
            }
        }

        vector<int> dp(n +1);
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1];
            for(int j = 0; j+k <= i; j++){
                if(isPalindrome[j][i-1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};