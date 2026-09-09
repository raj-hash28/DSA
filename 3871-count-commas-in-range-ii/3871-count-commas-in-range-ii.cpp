class Solution {
public:
    long long countCommas(long long n) {
        long long  result = 0;
        long long lower = 1000;
        int comma = 1;

        while(lower <= n){
            long long upper = lower*1000 - 1;
            if(upper > n){
                upper = n;
            }

            long long countNo = upper-lower+1;

            result = result+countNo*comma;

            lower = lower*1000;
            comma = comma+1;
        }

        return result;
    }
};