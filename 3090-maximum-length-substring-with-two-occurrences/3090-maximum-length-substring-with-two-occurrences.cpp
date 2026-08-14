class Solution {
public:
    int maximumLengthSubstring(string s) {
        int low = 0;
        int high = 0;
        unordered_map<int, int> f;
        int n = s.size();
        int res = 1;

        while(high < n){
            f[s[high]]++;

            while(f[s[high]] > 2){
                f[s[low]]--;
                low++;
            }
            int length = high-low+1;
            res = max(res, length);
            high++;
        }
        return res;
    }
};