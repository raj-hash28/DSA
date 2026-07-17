class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        bool insert = false;

        for(int i = 0; i < n; i++){
            if(insert == false and nums[i][0] >= newInterval[0]){
                result.push_back(newInterval);
                insert = true;
            }
            result.push_back(nums[i]);
        }
        if(insert == false)
        result.push_back(newInterval);

        vector<vector<int>> ans;
        int start1 = result[0][0];
        int end1 = result[0][1];

        for(int i = 1; i < result.size(); i++){
            int start2 = result[i][0];
            int end2 = result[i][1];

            if(end1 >= start2){
                start1 = start1;
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