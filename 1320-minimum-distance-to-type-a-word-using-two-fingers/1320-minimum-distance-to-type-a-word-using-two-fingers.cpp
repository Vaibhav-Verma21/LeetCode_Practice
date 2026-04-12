class Solution {
public:
    int minimumDistance(string word) {
        int length = word.size();
        const int INF = 1 << 30;

        // dp[i][f1][f2] = min cost after typing i-th character
        // with finger1 at f1 and finger2 at f2
        vector<vector<vector<int>>> dp(
            length, vector<vector<int>>(26, vector<int>(26, INF))
        );

        // Initialize first character
        for (int finger = 0; finger < 26; ++finger) {
            dp[0][word[0] - 'A'][finger] = 0;
            dp[0][finger][word[0] - 'A'] = 0;
        }

        for (int i = 1; i < length; ++i) {
            int prevChar = word[i - 1] - 'A';
            int currChar = word[i] - 'A';
            int moveCost = getDistance(prevChar, currChar);

            for (int otherFinger = 0; otherFinger < 26; ++otherFinger) {
                // Move same finger
                dp[i][currChar][otherFinger] = min(
                    dp[i][currChar][otherFinger],
                    dp[i - 1][prevChar][otherFinger] + moveCost
                );

                dp[i][otherFinger][currChar] = min(
                    dp[i][otherFinger][currChar],
                    dp[i - 1][otherFinger][prevChar] + moveCost
                );

                // Switch finger usage
                if (otherFinger == prevChar) {
                    for (int prevOther = 0; prevOther < 26; ++prevOther) {
                        int switchCost = getDistance(prevOther, currChar);

                        dp[i][currChar][otherFinger] = min(
                            dp[i][currChar][otherFinger],
                            dp[i - 1][prevOther][prevChar] + switchCost
                        );

                        dp[i][otherFinger][currChar] = min(
                            dp[i][otherFinger][currChar],
                            dp[i - 1][prevChar][prevOther] + switchCost
                        );
                    }
                }
            }
        }

        int result = INF;
        int lastChar = word[length - 1] - 'A';

        for (int finger = 0; finger < 26; ++finger) {
            result = min(result, dp[length - 1][lastChar][finger]);
            result = min(result, dp[length - 1][finger][lastChar]);
        }

        return result;
    }

    int getDistance(int char1, int char2) {
        int row1 = char1 / 6, col1 = char1 % 6;
        int row2 = char2 / 6, col2 = char2 % 6;
        return abs(row1 - row2) + abs(col1 - col2);
    }
};