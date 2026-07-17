class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int start1 = arr[0][0];
        int end1 = arr[0][1];
        vector<vector<int>> ans;

        int i;
        for(int i = 1; i < n; i++){
            int start2 = arr[i][0];
            int end2 = arr[i][1];

            if(end1 >= start2){
                //start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            ans.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        ans.push_back({start1, end1});
        return ans;
    }
};