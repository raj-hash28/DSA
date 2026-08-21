class Solution {
public:
    void helper(int open, int close, int n, string& temp, vector<string>& res){
        if(open == n and close == n){
            res.push_back(temp);
            return;
        } 

        if(open < n){
            temp.push_back('(');
            helper(open+1, close, n, temp, res);
            temp.pop_back();
        }

        if(close < open){
            temp.push_back(')');
            helper(open, close+1, n, temp, res);
            temp.pop_back();
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> res;
        helper(0, 0, n, temp, res);

        return res;
    }
};