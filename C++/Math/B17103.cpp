#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int gold[1'000'001];
vector<int> era;
bool vis[1'000'001], ch[1'000'001];

void eratos() {
	int sq = (int)sqrt(1'000'000);
	for (int i = 2; i <= 1'000'000; i++) {
		if (vis[i]) continue;

		era.push_back(i);
		if (i > sq) continue;
		for (int j = i * i; j <= 1'000'000; j += i) vis[j] = true;
	}
}

int solve(int num) {
	if (ch[num]) return gold[num];

	for (int i = 0; i < era.size() && era[i] <= num / 2; i++) {
		if (!vis[num - era[i]]) gold[num]++;
	}
	ch[num] = true;

	return gold[num];
}

int main() { //°ñµå¹ÙÈå ÆÄÆ¼¼Ç
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	eratos();

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		cout << solve(N) << "\n";
	}
}