#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int dp[100001][2];
void check(int i, int num, bool p) {
    if (dp[i - num][0] == dp[i][0] + 1) dp[i - num][1] = max(dp[i - num][1], p ? dp[i][1] + 1 : dp[i][1]);
    else if (dp[i - num][0] > dp[i][0] + 1) {
        dp[i - num][0] = dp[i][0] + 1;
        dp[i - num][1] = p ? dp[i][1] + 1 : dp[i][1];
    }
}

vector<int> solution(int target) {
    for (int i = 0; i <= 100000; i++) dp[i][0] = INT_MAX;
    dp[target][0] = 0;

    for (int i = target; i >= 0; i--) {
        if (i >= 50) check(i, 50, true);

        for (int j = 1; j <= 20; j++) {

            if (i >= j) check(i, j, true);
            if (i >= j * 2) check(i, j * 2, false);
            if (i >= j * 3) check(i, j * 3, false);
        }
    }

    vector<int> answer;
    answer.push_back(dp[0][0]);
    answer.push_back(dp[0][1]);
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target;
    cin >> target;

    vector<int> res = solution(target);
    cout << res[0] << " " << res[1];
}