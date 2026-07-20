class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(int idx, string digits, string s) {
        if(idx == digits.size()) {
            ans.push_back(s);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for(char c : letters) {
            solve(idx + 1, digits, s + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }

        solve(0, digits, "");
        return ans;
    }
};