
class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjls, vector<int>& vis)            // ← use vector<int>
    {
        vis[node] = 1;
        for (int nxt : adjls[node]) {
            if (!vis[nxt]) {              // ← guard against revisiting
                dfs(nxt, adjls, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();

        // --- build adjacency list as vector<vector<int>> -----------------
        vector<vector<int>> adjls(v);
        for (int i = 0; i < v; ++i) {
            for (int j = i + 1; j < v; ++j) {          // iterate only upper‑triangle
                if (isConnected[i][j]) {               // (i != j) implied
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        // --- DFS over components -----------------------------------------
        vector<int> vis(v, 0);
        int provinces = 0;

        for (int i = 0; i < v; ++i) {
            if (!vis[i]) {
                ++provinces;
                dfs(i, adjls, vis);
            }
        }
        return provinces;
    }
};
