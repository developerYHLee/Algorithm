#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vp;

bool cmp(pii o1, pii o2){
	if (o1.first == o2.first) return o1.second > o2.second;
	return o1.first < o2.first;
}

vp calendar(1001);
int f[1001]; //같은 날에 겹치는 일정

int main() { //달력
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int s, e;
		cin >> s >> e;

		calendar[i].first = s;
		calendar[i].second = e;
	}
	calendar[0].first = 1e9;

	sort(calendar.begin(), calendar.begin() + N + 1, cmp);
	
	int h = 0, w = 0, start = calendar[0].first, res = 0;
	for (int i = 0; i <= N; i++) {
		if (w < calendar[i].first - 1) {
			res += h * (w - start + 1);
			h = 0;
			w = 0;
			start = calendar[i].first;
		}

		int j = 1;
		while (f[j] >= calendar[i].first) j++;
		f[j] = calendar[i].second;
		h = max(h, j);
		w = max(w, calendar[i].second);
	}

	cout << res;
}