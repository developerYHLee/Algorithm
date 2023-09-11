#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> dp[500] = {};

vector<int> split(string str, char delimiter) {
    stringstream iss(str);
    string buffer;

    vector<int> res;
    while (getline(iss, buffer, delimiter)) res.push_back(stoi(buffer));

    return res;
}

int solution(vector<vector<int>> triangle) {
    int N = size(triangle);

    dp[0].push_back(triangle[0][0]);

    for (int i = 1; i < N; i++) {
        dp[i].push_back(dp[i - 1][0] + triangle[i][0]);
        for (int j = 1; j < i; j++) {
            int m = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            dp[i].push_back(m);
        }
        dp[i].push_back(dp[i - 1][i - 1] + triangle[i][i]);
    }

    int m = 0;
    for (int i = 0; i < N; i++) m = max(m, dp[N - 1][i]);

    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> v(N);
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        
        vector<int> num = split(str, ',');
        for (int j = 0; j < size(num); j++) v[i].push_back(num[j]);
    }

    cout << solution(v);
}