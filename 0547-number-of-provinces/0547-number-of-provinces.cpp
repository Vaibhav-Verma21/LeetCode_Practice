class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& isVis) {
        isVis[city] = true;
        // vis all connected
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[city][i] == 1 && !isVis[i]) {
                dfs(i, isConnected, isVis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> isVis(n, false);
        int proCnt = 0;

        // check every city
        for (int i = 0; i < n; ++i) {
            if (!isVis[i]) {
                // agar city notvis, its a new province
                dfs(i, isConnected, isVis);
                proCnt++; // province badhao
            }
        }

        return proCnt;
    }
};