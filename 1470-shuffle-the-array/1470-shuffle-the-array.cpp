class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int m = nums.size();
        vector<int> ans(n * 2);
        int j = 0, k = n;
        for (int i = 0; i < n * 2; i += 2) {
            ans[i] = nums[j++];
            ans[i + 1] = nums[k++];
        }

        return ans;
    }
};