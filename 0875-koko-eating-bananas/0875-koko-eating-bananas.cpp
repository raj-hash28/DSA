class Solution {
public:
long long helper(vector<int>& piles, int n, int speed){
    long long h = 0;

    for(int i = 0; i < n; i++){
        h = h + piles[i]/speed;
        if(piles[i] % speed != 0){
            h++;
        }
    }
    return h;
}

    int minEatingSpeed(vector<int>& piles, int guard_time) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        int n = piles.size();

        while(low <= high){
            int mid = low + (high - low)/2;

            long long hours = helper(piles, n, mid);
            if(hours > guard_time){
                low = mid+1;
            }
            else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};