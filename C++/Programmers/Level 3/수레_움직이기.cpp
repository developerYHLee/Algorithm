#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
typedef vector<vector<int>> vvi;

int N, M, ans, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, r[2], c[2];
vvi maze;
bool redVis[5][5], blueVis[5][5];

void input() {
    N = maze.size();
    M = maze[0].size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == 1) {
                r[0] = i;
                c[0] = j;
            }

            if (maze[i][j] == 2) {
                r[1] = i;
                c[1] = j;
            }
        }
    }

    redVis[r[0]][c[0]] = true;
    blueVis[r[1]][c[1]] = true;
    ans = INT_MAX;
}

bool checkRowCol(int row, int col, const bool(&vis)[5][5]) {
    if (row < 0 || col < 0 || row >= N || col >= M || maze[row][col] == 5 || vis[row][col]) return false;
    return true;
}

void recur(int redRow, int redCol, int blueRow, int blueCol, int cnt) {
    if (maze[redRow][redCol] == 3 && maze[blueRow][blueCol] == 4) {
        ans = min(ans, cnt);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int redR = redRow, redC = redCol;

        if (maze[redRow][redCol] != 3) {
            redR += dx[i];
            redC += dy[i];

            if (!checkRowCol(redR, redC, redVis)) continue;
        }

        for (int j = 0; j < 4; j++) {
            int blueR = blueRow, blueC = blueCol;

            if (maze[blueRow][blueCol] != 4) {
                blueR += dx[j];
                blueC += dy[j];

                if (!checkRowCol(blueR, blueC, blueVis)) continue;
            }

            if (redR == blueR && redC == blueC) continue;
            if (redR == blueRow && redC == blueCol && blueR == redRow && blueC == redCol) continue;

            redVis[redR][redC] = true;
            blueVis[blueR][blueC] = true;

            recur(redR, redC, blueR, blueC, cnt + 1);

            redVis[redR][redC] = false;
            blueVis[blueR][blueC] = false;
        }
    }
}

void solve() {
    recur(r[0], c[0], r[1], c[1], 0);
    ans = ans == INT_MAX ? 0 : ans;
}

int solution(vector<vector<int>> m) {
    maze = m;
    input();
    solve();

    return ans;
}