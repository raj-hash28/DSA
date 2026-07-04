class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high = 0;
        int n = s.size();
        unordered_map<char, int> f;
        int result = INT_MIN;

        for(high = 0; high < n; high++){
            f[s[high]]++;
            int k = high-low+1;

            while(f.size() < k){
                f[s[low]]--;
                if(f[s[low]] == 0) f.erase(s[low]);
                low++;

                k = high-low+1;
            }
            int length = high-low+1;
            result = max(result, length);
        }
        return (result == INT_MIN) ? 0 : result;
    }
};