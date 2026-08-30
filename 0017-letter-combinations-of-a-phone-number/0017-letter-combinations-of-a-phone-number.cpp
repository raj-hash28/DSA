class Solution {
public:
    void helper(string& s, int n, int idx, string& diary, vector<string>& res){
        unordered_map<char, string> f;

        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        if(idx==n){
            res.push_back(diary);
            return;
        }

        string choices = f[s[idx]];

        for(int j = 0; j < choices.size(); j++){
            diary.push_back(choices[j]);
            helper(s, n, idx+1, diary, res);
            diary.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string s) {
        int n = s.size();

        if(s.empty()) return {};
        vector<string> res;
        string diary = "";
        helper(s, n, 0, diary, res);
        return res;
    }
};