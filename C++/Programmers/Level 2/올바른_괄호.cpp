#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> S;

    for (int i = 0; i < size(s); i++) {
        if (s[i] == '(') S.push('(');
        else {
            if (S.size() == 0) return false;
            S.pop();
        }
    }

    return S.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    cin >> str;

    cout << solution(str);
}