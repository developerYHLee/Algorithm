#include <string>
#include <vector>

using namespace std;

int sH, sM, sS, eH, eM, eS, ans;

int calSecond(int h, int m, int s) {
    return s + m * 60 + h * 3600;
}

int calAlarm(int s) {
    int aM = s * 59 / 3600;
    int aH = s * 719 / 43200;
    int aHM = s >= 43200 ? 2 : 1;

    return aM + aH - aHM;
}

void solve() {
    int s1 = calSecond(sH, sM, sS);
    int s2 = calSecond(eH, eM, eS);

    ans = calAlarm(s2) - calAlarm(s1);
    if (!(s1 * 59 % 3600) || !(s1 * 719 % 43200)) ans++;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    sH = h1; sM = m1; sS = s1; eH = h2; eM = m2; eS = s2;
    solve();

    return ans;
}