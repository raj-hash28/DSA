class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        vector<int> t;
        int score = 0;

        for(int i = 0; i < n; i++){
           if(s[i] == '('){
            t.push_back(score);
            score = 0;
           } 
           else {
                if(s[i-1] == '('){
                    score = t.back() + 1;
                }
                else {
                    score = t.back() + (2*score);
                }
                t.pop_back();
           }
        }
        return score;
    }
};