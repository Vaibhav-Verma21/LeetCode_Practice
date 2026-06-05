class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[17][2][2][3][11][11];
    bool vis[17][2][2][3][11][11];

    Node dfs(int pos, int tight, int started,
             int lenState, int prev2, int prev1) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][tight][started][lenState][prev2][prev1])
            return dp[pos][tight][started][lenState][prev2][prev1];

        int limit = tight ? s[pos] - '0' : 9;

        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, ntight, 0, 0, 10, 10);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
                continue;
            }

            if (!started) {
                Node nxt = dfs(pos + 1, ntight, 1, 1, 10, d);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else if (lenState == 1) {
                Node nxt = dfs(pos + 1, ntight, 1, 2, prev1, d);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else {
                int add = 0;

                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d))
                    add = 1;

                Node nxt = dfs(pos + 1, ntight, 1, 2, prev1, d);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + add * nxt.cnt;
            }
        }

        if (!tight) {
            vis[pos][tight][started][lenState][prev2][prev1] = true;
            dp[pos][tight][started][lenState][prev2][prev1] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, 0, 10, 10).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};