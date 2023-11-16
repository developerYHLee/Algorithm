#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> ans, vis(11), info;
int MAX = 0;

void check() {
    if (vis.size() > ans.size()) {
        ans = vis;
        return;
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        if (vis[i] == ans[i]) continue;
        else if (vis[i] > ans[i]) {
            ans = vis;
            return;
        }
        else return;
    }
}

int compare_score() {
    int score = 0;
    for (int i = 0; i < vis.size(); i++) {
        if (vis[i] == 0 && info[i] == 0) continue;
        if (vis[i] > info[i]) score += 10 - i;
        else score -= 10 - i;
    }

    return score;
}

void solve(int index, int cnt) {
    if (cnt == 0) {
        int score = compare_score();

        if (MAX < score) {
            MAX = score;
            ans = vis;
        }
        else if (MAX == score) check();
		 
        return;
    }

    for (int i = index; i < 10; i++) {
        if (info[i] >= cnt) continue;

        vis[i] = info[i] + 1;
        cnt -= info[i] + 1;
        solve(i + 1, cnt);
        vis[i] = 0;
        cnt += info[i] + 1;
    }

    if (cnt > 0) {
        vis[10] = cnt;
        solve(10, 0);
        vis[10] = 0;
    }
}

vector<int> solution(int n, vector<int> infos) {
    info = infos;

    solve(0, n);

    if (MAX > 0) return ans;
    else return { -1 };

    return ans;
}