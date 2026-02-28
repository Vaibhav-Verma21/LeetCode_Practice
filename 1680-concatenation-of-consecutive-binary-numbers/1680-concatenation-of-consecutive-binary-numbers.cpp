class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int length = 0;

        for (int i = 1; i <= n; ++i) {
            length = log2(i) + 1;
            result = (result * (1 << length) + i) % MOD;
        }

        return result;
    }
};