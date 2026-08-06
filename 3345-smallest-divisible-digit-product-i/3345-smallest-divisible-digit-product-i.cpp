class Solution {
private:
    int product(int n){
        int p = 1;
        while(n != 0){
            p = p*(n%10);  //gives last digit
            n = n/10;     // gives the remaning digit
        }
        return p;
    }
public:
    int smallestNumber(int n, int t) {
        while(product(n) % t != 0){
            n++;
        }
        return n;
    }
};