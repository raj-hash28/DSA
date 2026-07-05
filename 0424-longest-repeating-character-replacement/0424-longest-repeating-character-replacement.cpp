class Solution {
    int find(vector<int> &a){
        int maxcount = -1;
        for(int i = 0; i < 256;i++)
        maxcount = max(maxcount, a[i]);
        return maxcount;
    }
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0, high = 0, result = INT_MIN;
        vector<int> f(256, 0);

        for(high = 0; high < n; high++){
            f[s[high]]++;

            int maxcount = find(f);
            int length = high-low+1;
            int difference = length - maxcount;

            while(difference > k){
                f[s[low]]--;
                low++;
                maxcount = find(f);
                length = high-low+1;
                difference = length - maxcount;
            }

            if(difference <= k){
                length = high-low+1;
                result = max(result, length);
            }  
        }
        return result;
    }
};