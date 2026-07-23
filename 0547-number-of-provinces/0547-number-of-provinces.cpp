class Solution {
public:
    void dfs(vector<vector<int>>& a, vector<int>& vis, int i) {
        vis[i] = 1;
        for (int j = 0; j < a.size(); j++)
            if (a[i][j] && !vis[j])
                dfs(a, vis, j);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(isConnected, vis, i);
                ans++;
            }
        }

        return ans;
    }
};