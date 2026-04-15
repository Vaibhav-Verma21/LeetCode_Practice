class Solution {
public:
    int closestTarget(vector<string>& w, string t, int s) {
        int n = w.size();
        int ans = n;

        for (int i = 0; i < n; ++i) {
            if (w[i] == t) {
                int d = abs(i - s);
                int alt = n - d;
                ans = min(ans, min(d, alt));
            }
        }

        return ans == n ? -1 : ans;
    }
};