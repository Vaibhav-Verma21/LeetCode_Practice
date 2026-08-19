class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];
            rows[row] |= (1 << s);
        }

        int ans = (n - rows.size()) * 2;

        int leftMask = 0;
        for (int s = 2; s <= 5; s++)
            leftMask |= (1 << s);

        int middleMask = 0;
        for (int s = 4; s <= 7; s++)
            middleMask |= (1 << s);

        int rightMask = 0;
        for (int s = 6; s <= 9; s++)
            rightMask |= (1 << s);

        for (auto& [row, mask] : rows) {
            bool left = (mask & leftMask) == 0;
            bool middle = (mask & middleMask) == 0;
            bool right = (mask & rightMask) == 0;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};
