#include <string>
#include <vector>
#include <memory.h>
#include <cmath>

using namespace std;
typedef vector<vector<int>> vvi;

bool vis[500][500], visCol[500];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, cnt, sz[500], N, M;
vvi land;
vector<int> arr;

void dfs(int row, int col) {
    vis[row][col] = true;
    cnt++;

    if (!visCol[col]) {
        arr.push_back(col);
        visCol[col] = true;
    }

    for (int i = 0; i < 4; i++) {
        int r = row + dx[i];
        int c = col + dy[i];

        if (r < 0 || c < 0 || r >= N || c >= M || vis[r][c] || !land[r][c]) continue;
        dfs(r, c);
    }
}

int solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (land[i][j] && !vis[i][j]) {
                cnt = 0;
                memset(visCol, false, sizeof(visCol));
                arr.clear();

                dfs(i, j);

                for (int k : arr) sz[k] += cnt;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < M; i++) res = max(res, sz[i]);
    return res;
}

int solution(vector<vector<int>> input_l) {
    N = input_l.size(); M = input_l[0].size();
    land = input_l;

    return solve();
}