class Solution {
public:
    const int MOD = 1e9 + 7;
    int LOG;
    vector<vector<int>> up; // binary lifting table
    vector<int> depth;
    vector<vector<int>> adj;

    void dfs(int u, int p) {
        up[u][0] = p;
        for (int j = 1; j < LOG; j++) {
            if (up[u][j-1] != -1)
                up[u][j] = up[up[u][j-1]][j-1];
            else
                up[u][j] = -1;
        }
        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int j = LOG-1; j >= 0; j--) {
            if ((diff >> j) & 1) u = up[u][j];
        }
        if (u == v) return u;
        for (int j = LOG-1; j >= 0; j--) {
            if (up[u][j] != -1 && up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    long long modpow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = 20; // since n <= 1e5, log2(1e5) < 20
        adj.assign(n+1, {});
        up.assign(n+1, vector<int>(LOG, -1));
        depth.assign(n+1, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, -1);

        vector<int> ans;
        for (auto &q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            int l = lca(u, v);
            int k = depth[u] + depth[v] - 2*depth[l];
            ans.push_back(modpow(2, k-1));
        }
        return ans;
    }
};
