#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

int ans;

void cal(int N) {
    ll ret = pow(5, N), p = 0;

    while (N-- > 0) {
        ret -= pow(5, N) * pow(4, p++);
    }

    ans += ret;
}

ll check_range(ll a, ll num) {
    return (num - 1) % a + 1;
}

void solve(int N, ll l, ll r) {
    if (N == 0) return;

    ll a = pow(5, N - 1);

    for (int i = 1; i <= 5; i++) {
        if (i == 3) continue;

        ll start = (i - 1) * a + 1, end = i * a;

        if (start >= l && end <= r) cal(N - 1);
        else if (start <= l && r <= end) solve(N - 1, check_range(a, l), check_range(a, r));
        else if (start <= l && l <= end) solve(N - 1, check_range(a, l), a);
        else if (start <= r && r <= end) solve(N - 1, 1, check_range(a, r));
    }
}

int solution(int n, long long l, long long r) {
    solve(n, l, r);
    return ans;
}