class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int high = 0;
        int result = INT_MIN;
        int n = fruits.size();
        unordered_map<int,int> f;

        for(high = 0; high < n; high++){
            f[fruits[high]]++;
            //int size = f.size();

            while(f.size() > 2){
                f[fruits[low]]--;
                if(f[fruits[low]] == 0) f.erase(fruits[low]);
                low++;
            }

            int length = high-low+1;
            result = max(result, length);
        }
        return result;
    }
};