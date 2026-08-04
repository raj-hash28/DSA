class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());

        //creating a set to store the values 
        unordered_set<int> present(nums.begin(), nums.end());

        for(int i = smallest; i < largest; i++){
            if(!present.contains(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};