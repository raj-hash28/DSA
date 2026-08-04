class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low+high)/2;

            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] > nums[n-1]){            //part1
                if(nums[mid] < target)
                    //right jao
                    low = mid+1;
                else {
                    if(nums[0] > target)
                        //right jao
                        low = mid+1;
                    else 
                        high = mid-1;
                }
                continue;              
            }

            if(nums[mid] > target)
                high = mid-1;
            else {
                if(nums[n-1] < target)
                    //right jao
                    high = mid-1;
                else 
                    //left jao
                    low = mid+1;
            } 
        }
        return -1;
    }
};