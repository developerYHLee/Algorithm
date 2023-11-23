#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<int>> in;

void get_info(const vector<string>& v, string str, int index, int cnt, int score) {
    if (cnt == 4) {
        in[str].push_back(score);
        return;
    }

    for (int i = index; i < v.size(); i++) {
        get_info(v, str + v[index], i + 1, cnt + 1, score);
        get_info(v, str + '-', i + 1, cnt + 1, score);
    }
}

void input_info(const vector<string>& info) {
    for (int i = 0; i < info.size(); i++) {
        vector<string> v;

        istringstream iss(info[i]);
        string str;

        for (int j = 0; j < 4; j++) {
            iss >> str;
            v.push_back(str);
        }
        iss >> str;

        int num = stoi(str);
        get_info(v, "", 0, 0, num);
    }
}

vector<string> input_query(string q) {
    istringstream iss(q);
    string temp, str = "";

    for (int i = 0; i < 4; i++) {
        iss >> temp;
        str += temp;

        iss >> temp;
    }

    return { str, temp };
}

int b_search(string key, int score) {
    int l = 0, r = in[key].size();

    while (l < r) {
        int m = (l + r) / 2;

        if (in[key][m] >= score) r = m;
        else l = m + 1;
    }

    return r;
}

vector<int> solution(vector<string> info, vector<string> query) {
    input_info(info);
    for (auto& it : in) sort(it.second.begin(), it.second.end());

    vector<int> answer;
    for (int i = 0; i < query.size(); i++) {
        vector<string> cur = input_query(query[i]);
        string key = cur[0];
        int score = stoi(cur[1]), q_size = in[key].size(), index = b_search(key, score);

        answer.push_back(q_size - index);
    }

    return answer;
}