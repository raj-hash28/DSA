class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;

        for(char& ch : s){
            if(ch == '('){
                st.push(res.length());
            }
            else if(ch == ')'){
                int l = st.top();
                st.pop();
                reverse(res.begin()+l, res.end());
            }
            else{
                res.push_back(ch);
            }
        }

        return res;
    }
};