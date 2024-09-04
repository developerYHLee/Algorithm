#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int N;
string DNA;
unordered_map<int, char> info;

int encodingDNA(char c, int p) {
	return (c - 'A') * (int)pow(100, p);
}

void setInfo() {
	info.insert({ encodingDNA('A', 1) + encodingDNA('A', 0), 'A' });
	info.insert({ encodingDNA('A', 1) + encodingDNA('G', 0), 'C' });
	info.insert({ encodingDNA('A', 1) + encodingDNA('C', 0), 'A' });
	info.insert({ encodingDNA('A', 1) + encodingDNA('T', 0), 'G' });

	info.insert({ encodingDNA('G', 1) + encodingDNA('A', 0), 'C' });
	info.insert({ encodingDNA('G', 1) + encodingDNA('G', 0), 'G' });
	info.insert({ encodingDNA('G', 1) + encodingDNA('C', 0), 'T' });
	info.insert({ encodingDNA('G', 1) + encodingDNA('T', 0), 'A' });

	info.insert({ encodingDNA('C', 1) + encodingDNA('A', 0), 'A' });
	info.insert({ encodingDNA('C', 1) + encodingDNA('G', 0), 'T' });
	info.insert({ encodingDNA('C', 1) + encodingDNA('C', 0), 'C' });
	info.insert({ encodingDNA('C', 1) + encodingDNA('T', 0), 'G' });

	info.insert({ encodingDNA('T', 1) + encodingDNA('A', 0), 'G' });
	info.insert({ encodingDNA('T', 1) + encodingDNA('G', 0), 'A' });
	info.insert({ encodingDNA('T', 1) + encodingDNA('C', 0), 'G' });
	info.insert({ encodingDNA('T', 1) + encodingDNA('T', 0), 'T' });
}

void input() {
	cin >> N >> DNA;
}

void solve() {
	setInfo();

	while (DNA.size() > 1) {
		char a1 = DNA[DNA.size() - 2], a2 = DNA[DNA.size() - 1];
		DNA.pop_back(); DNA.pop_back();
		DNA.push_back(info[encodingDNA(a1, 1) + encodingDNA(a2, 0)]);
	}

	cout << DNA;
}

int main() { //DNA ÇØµ¶
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}