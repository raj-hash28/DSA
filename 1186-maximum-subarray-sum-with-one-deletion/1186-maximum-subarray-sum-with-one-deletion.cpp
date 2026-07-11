class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = INT_MIN;
        int ans = arr[0];
        int n = arr.size();

        for(int i = 1; i < n; i++){
            int prev_noDelete = noDelete;
            int prev_oneDelete = oneDelete;
            noDelete = max(noDelete + arr[i], arr[i]);

            int v2;
            if(prev_oneDelete == INT_MIN){
                v2 = arr[i];
            }
            else {
                v2 = prev_oneDelete + arr[i];
            }
            oneDelete = max(v2, prev_noDelete);
            ans = max(ans, max(oneDelete, noDelete));
        }
        return ans;
    }
};