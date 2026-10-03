class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> st;
        st.push(-1); // Base index for boundary tracking
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // New base index for invalid boundary
                } else {
                    maxLength = std::max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};