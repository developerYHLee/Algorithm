#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> card;
int index[1000001], res[100000];
bool vis[1000001];
 
//i : 선택한 카드, o : 비교할 카드
void check(int i, int o) {
	if (vis[o]) {
		res[i]--;
		res[index[o]]++;
	}
}

void solve(int N) {
	for (int i = 0; i < N; i++) {
		int num = card[i], sqrt_num = (int)sqrt(num);

		vector<int> div;
		for (int j = 1; j <= sqrt_num; j++) {
			if (num % j == 0) {
				div.push_back(j);
				if (j * j != num) div.push_back(num / j);
			}
		}

		int div_size = div.size();
		for (int j = 0; j < div_size; j++) check(i, div[j]);
	}
}

void eratos(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = card[i] * 2; j <= 1000000; j += card[i]) {
			if (vis[j]) {
				res[i]++;
				res[index[j]]--;
			}
		}
	}
}

int main() { //수 나누기 게임
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		vis[n] = true;
		index[n] = i;
		card.push_back(n);
	}

	solve(N);
	//eratos(N);

	for (int i = 0; i < N; i++) cout << res[i] << " ";
}