class Solution {
    bool check(int zero, int one, int two) {
        if (one == 0) return false; 
        one--;
        int mn = min(one, two), len = 1 + mn * 2 + zero;
        one -= mn, two -= mn;
        if (one) {
            ++len;
            --one;
        }
        return len % 2 && one + two;
    }
public:
    bool stoneGameIX(vector<int>& A) {
        int c[3] = {};
        for (int n : A) c[n % 3]++;
        return check(c[0], c[1], c[2]) || check(c[0], c[2], c[1]);
    }
};
