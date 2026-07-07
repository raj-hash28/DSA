class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        //optimized approach
        
        for(int i = 0; i < n; i++){
            //total subarray containing arr[i] 
            int total_subarray = (i+1)*(n-i);

            //total odd-lenght subarray containing arr[i]
            int odd_subarray = (total_subarray+1)/2;

            sum = sum + arr[i] * odd_subarray;
        }
        return sum;
    }
};
