#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int room[100001], res;
vector<piii> t;
priority_queue<pii, vector<pii>, greater<pii>> PQ;

void set_room(int prev_r, int index, bool sizeUp) {
	if (sizeUp) {
		int e = t[index].second.first, r = t[index].second.second;
		PQ.push({ e, r });
		res = max(res, (int)PQ.size());
		room[r] = PQ.size();
	}
	else {
		PQ.pop();
		int e = t[index].second.first, r = t[index].second.second;
		PQ.push({ e, r });
		room[r] = room[prev_r];
	}
}

void check_PQ(int index) {
	if (PQ.size() == 0) {
		set_room(-1, index, true);
	}
	else {
		pii cur = PQ.top();
		int e = cur.first, r = cur.second, next_s = t[index].first;

		if (e <= next_s) set_room(r, index, false);
		else set_room(-1, index, true);
	}
}

int main() { //°­ÀÇ½Ç 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	t.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		int r, s, e;
		cin >> r >> s >> e;

		t[i] = { s, {e, r} };
	}
	sort(t.begin(), t.end());

	for (int i = 1; i <= N; i++) check_PQ(i);
	
	cout << res << '\n';
	for (int i = 1; i <= N; i++) cout << room[i] << '\n';
}