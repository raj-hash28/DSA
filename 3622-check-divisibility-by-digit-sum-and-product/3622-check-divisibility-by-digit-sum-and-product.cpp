class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int product = 1;

        while(n != 0){
            int lastDigit = n % 10;
            sum += lastDigit;
            product *= lastDigit;
            n = n / 10;
        }

        int c = sum + product;
        return (original % c) == 0;
    }
};