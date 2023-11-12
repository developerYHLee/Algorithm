#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef vector<string> vs;

bool vis[8];
vs u_i, b_i;
set<string> S;

bool check(string u, string b) {
    if (u.size() != b.size()) return false;

    for (int i = 0; i < u.size(); i++) {
        if (u[i] != b[i] && b[i] != '*') return false;
    }

    return true;
}

void backtraking(int index, int cnt, string str) {
    if (cnt == b_i.size()) {
        sort(str.begin(), str.end());
        if (S.find(str) == S.end()) S.insert(str);

        return;
    }

    for (int i = index; i < u_i.size(); i++) {
        string u = u_i[i];
        for (int j = 0; j < b_i.size(); j++) {
            if (vis[j]) continue;

            string b = b_i[j];
            if (!check(u, b)) continue;

            vis[j] = true;
            backtraking(i + 1, cnt + 1, str + to_string(i));
            vis[j] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    u_i = user_id;
    b_i = banned_id;

    backtraking(0, 0, "");

    return S.size();
}