class Solution {
public:
    typedef long long ll;

    ll countSmaller(ll mid, vector<int> coins){
        ll correctedCount = 0;
        int n = coins.size();

        for(int expressions = 1; expressions < (1 << n); expressions++){
            ll lcm = 0;
            ll order = 0;

            for(int i = 0; i < n; i++){
                if(expressions & (1 << i)){
                    order++;

                    if(lcm == 0){
                        lcm = coins[i];
                    }
                    else {
                        lcm = lcm * coins[i]/gcd(lcm, coins[i]);
                    }
                }
            }
            
            if(order % 2 == 0){
                correctedCount -= mid/lcm;
            }
            else {
                correctedCount += mid/lcm;
            }
        }

        return correctedCount;
    }

    ll findKthSmallest(vector<int>& coins, int k) {
        ll result = -1;
        ll low = 1;
        ll high = (ll)(*max_element(coins.begin(), coins.end()))*k;

        while(low <= high){
            ll mid = low + (high-low)/2;

            if(countSmaller(mid, coins) >= k){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};