#include <iostream>

using namespace std;

void printString(string str) {
	cout << str << "\n";
}

void printHeart() {
	printString(" @@@   @@@ ");
	printString("@   @ @   @");
	printString("@    @    @");
	printString("@         @");
	printString(" @       @ ");
	printString("  @     @  ");
	printString("   @   @   ");
	printString("    @ @    ");
	printString("     @     ");
}

int main() { //Serca
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	while (N-- > 0) printHeart();
}