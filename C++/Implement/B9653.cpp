#include <iostream>

using namespace std;

void print_str(string str) {
	cout << str << "\n";
}

int main() { //스타워즈 로고
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	print_str("    8888888888  888    88888");
	print_str("   88     88   88 88   88  88");
	print_str("    8888  88  88   88  88888");
	print_str("       88 88 888888888 88   88");
	print_str("88888888  88 88     88 88    888888");
	print_str("");
	print_str("88  88  88   888    88888    888888");
	print_str("88  88  88  88 88   88  88  88");
	print_str("88 8888 88 88   88  88888    8888");
	print_str(" 888  888 888888888 88  88      88");
	print_str("  88  88  88     88 88   88888888");
}