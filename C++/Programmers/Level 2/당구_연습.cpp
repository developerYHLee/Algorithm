#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int x, y, N, M;
vvi B;
vi ans;

void solve() {
    for (vi pos : B) {
        int tmpX = pos[0], tmpY = pos[1], dis = 1e9;

        if (!(x == tmpX && y > tmpY)) dis = min(dis, (int)(pow(abs(x - tmpX), 2) + pow(y + tmpY, 2)));
        if (!(x == tmpX && y < tmpY)) dis = min(dis, (int)(pow(abs(x - tmpX), 2) + pow(2 * N - y - tmpY, 2)));
        if (!(x > tmpX && y == tmpY)) dis = min(dis, (int)(pow(x + tmpX, 2) + pow(abs(y - tmpY), 2)));
        if (!(x < tmpX && y == tmpY)) dis = min(dis, (int)(pow(2 * M - x - tmpX, 2) + pow(abs(y - tmpY), 2)));

        ans.push_back(dis);
    }
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    B = balls;
    N = n; M = m; x = startX; y = startY;
    solve();

    return ans;
}