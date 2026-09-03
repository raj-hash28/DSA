class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int smallest_odd = INT_MAX;
        int smallest_even = INT_MAX;

        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 != 0){
                smallest_odd = min(smallest_odd, nums1[i]);
            }
            else{
                smallest_even = min(smallest_even, nums1[i]);
            }
        }

        if(smallest_odd == INT_MAX) return true;

        if(smallest_even < smallest_odd) {
            return false;
        }

        else {
            return true;
        }
    }
};