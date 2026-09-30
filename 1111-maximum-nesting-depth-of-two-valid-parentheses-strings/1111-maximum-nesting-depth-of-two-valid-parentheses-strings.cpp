class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> ans;
        for(char& ch : seq){
            if(ch == '('){
                d++;
                ans.push_back(d%2);
            }
            else {
                ans.push_back(d%2);
                d--;
            }
        }
        return ans;
    }
};