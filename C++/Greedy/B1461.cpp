#include <iostream>
#include <queue>

using namespace std;

int N, M, res;
priority_queue<int> p, m;

void pop_p(bool end) {
	int temp = p.top();

	for (int i = 0; i < M; i++) {
		if (p.empty()) break;
		p.pop();
	}
	
	if (!end) temp *= 2;

	res += temp;
}

void pop_m(bool end) {
	int temp = m.top();

	for (int i = 0; i < M; i++) {
		if (m.empty()) break;
		m.pop();
	}

	if (!end) temp *= 2;

	res += temp;
}

int main() { //µµ¼­°ü
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (n < 0) m.push(-n);
		else p.push(n);
	}

	if(!p.empty() && m.empty()) pop_p(true);
	else if (p.empty() && !m.empty()) pop_m(true);
	else {
		if (p.top() > m.top()) pop_p(true);
		else pop_m(true);
	}

	while (!p.empty()) pop_p(false);
	while (!m.empty()) pop_m(false);

	cout << res;
}