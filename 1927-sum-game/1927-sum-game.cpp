class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftSum = 0, rightSum = 0;
        int leftBlank = 0, rightBlank = 0;

        // Count sums and blanks for both halves
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                leftBlank++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                rightBlank++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        // If the total number of '?' is odd, Alice gets the last move and always wins
        if ((leftBlank + rightBlank) % 2 != 0) {
            return true;
        }

        // For Bob to win, every pair of '?' on one side must compensate
        // the difference in sums by an average value of 4.5 per '?' (or 9 per pair).
        // Condition for Bob winning: (leftSum - rightSum) == (rightBlank - leftBlank) * 4.5
        // Alice wins if this condition does NOT hold:
        return (leftSum - rightSum) * 2 != (rightBlank - leftBlank) * 9;
    }
};