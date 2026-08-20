class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> list1;
        vector<int> list2;
        list1.push_back(nums[0]);
        list2.push_back(nums[1]);

        for(int i = 2; i < n; i++){
            if(list1.back() > list2.back()){
                list1.push_back(nums[i]);
            }
            else{
                list2.push_back(nums[i]);
            }
        }

        vector<int> result;

        for(auto i : list1){
            result.push_back(i);
        }
        for(auto i : list2){
            result.push_back(i);
        }

        return result;

    }
};