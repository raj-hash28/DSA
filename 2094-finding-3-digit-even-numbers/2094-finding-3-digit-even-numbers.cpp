class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> num;
        int n = digits.size();
        unordered_set<int> s;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                for(int k = 0; k < n; k++){
                    if(i == k) continue;
                    if(j == k) continue;

                    int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(number >= 100){
                        s.insert(number);
                    }
                }
            }
        }

        for(int i : s){
            if(i % 2 == 0)
                num.push_back(i);
        }

        sort(num.begin(), num.end());
        // num.sort(num.begin(), num.end());

        return num;
    }
};