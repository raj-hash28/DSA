class Solution {
    bool sahi(vector<int>& have, vector<int>& need){
        for(int i = 0; i < 256; i++){
            if(have[i] < need[i]){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> have(256,0);
        vector<int> need(256,0);
        if(n<m)
        return "";

        for(int i = 0; i < m; i++){
            need[t[i]]++;
        }

        int low = 0, high = 0; 
        int result = INT_MAX;
        int start = -1;
        for(high = 0; high < n; high++){
            have[s[high]]++;

            while(sahi(have, need)){
                int length = high-low+1;
                if(result > length){
                    result = length;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if(result == INT_MAX)
        return "";
        return s.substr(start, result);
    }
};