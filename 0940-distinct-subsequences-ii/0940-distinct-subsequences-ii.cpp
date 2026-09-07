class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9+7;
        vector<long> last(26,0);

        for(char c : s){
            int idx = c-'a';
            long total = 1;

            for(int i = 0; i < 26; i++){
                total = (total+last[i]) % MOD;
            }

            last[idx] = total;
        }

        long ans = 0;

        for(int i = 0; i < 26; i++){
            ans = (ans+last[i]) % MOD;
        }

        return ans;
    }
};