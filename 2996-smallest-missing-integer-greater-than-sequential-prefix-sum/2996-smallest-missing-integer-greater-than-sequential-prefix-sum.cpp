class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

        //j will start from 1
        for(int j = 1; j < n; j++){
            if(nums[j] == nums[j-1]+1){
                sum = sum + nums[j];
            }
            else break;
        }

        unordered_set<int> s;
        //insert nums element 
        for(auto &val: nums){
            s.insert(val);
        }

        while(s.find(sum) != s.end()){
            sum++;
        }

        return sum;
    }
};