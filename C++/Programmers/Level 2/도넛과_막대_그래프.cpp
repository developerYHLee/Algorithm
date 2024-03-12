#include <string>
#include <vector>
#include <memory.h>

using namespace std;

const int MAX_N = 1000001;
vector<int> ans, E[MAX_N];
int _in[MAX_N], _out[MAX_N], N;
bool vis[MAX_N], G[MAX_N];

void setInput(vector<vector<int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i][0], b = edges[i][1];

        E[a].push_back(b);
        _in[b]++;
        _out[a]++;

        if (!vis[a]) {
            vis[a] = true;
            N++;
        }
        if (!vis[b]) {
            vis[b] = true;
            N++;
        }
    }
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < 4; i++) ans.push_back(0);
}

bool dfs(int node) {
    for (int i : E[node]) {
        if (G[i]) return false;

        if (vis[i]) continue;
        vis[i] = true;

        if (!dfs(i)) {
            G[i] = true;
            return false;
        }
    }

    return true;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        if (!_in[i] && _out[i] > 1) ans[0] = i;
        else if (_in[i] >= 1 && !_out[i]) {
            ans[2]++;
            G[i] = true;
        }
        else if (_in[i] >= 2 && _out[i] == 2) {
            ans[3]++;
            G[i] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (G[i] || vis[i] || i == ans[0]) continue;
        if (dfs(i)) ans[1]++;
    }
}

vector<int> solution(vector<vector<int>> edges) {
    setInput(edges);
    solve();
    return ans;
}