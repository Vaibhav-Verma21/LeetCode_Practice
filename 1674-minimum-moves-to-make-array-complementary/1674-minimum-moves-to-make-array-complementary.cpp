class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b);
            int high = max(a, b);

            // Assume 2 moves for all sums
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // 1 move range
            diff[low + 1] -= 1;
            diff[high + limit + 1] += 1;

            // 0 move at exact sum
            diff[low + high] -= 1;
            diff[low + high + 1] += 1;
        }

        int ans = INT_MAX;
        int cur = 0;

        for (int sum = 2; sum <= 2 * limit; sum++) {
            cur += diff[sum];
            ans = min(ans, cur);
        }

        return ans;
    }
};