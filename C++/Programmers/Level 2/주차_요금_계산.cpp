#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

vector<string> split(string str) {
    vector<string> res;

    stringstream ss(str);
    string buffer;

    while (ss >> buffer) res.push_back(buffer);

    return res;
}

int change_to_min(string str) {
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3));

    return h * 60 + m;
}

int car_cost[10000], car_time[10000];
bool vis[10000];

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int m = fees[0], cost = fees[1], m_a = fees[2], cost_a = fees[3];

    for (int i = 0; i < records.size(); i++) {
        vector<string> temp = split(records[i]);

        int t_m = change_to_min(temp[0]), t_car = stoi(temp[1]);
        string o = temp[2];

        if (o.compare("IN") == 0) {
            car_time[t_car] = t_m;
            vis[t_car] = true;
        }
        else {
            int c = t_m - car_time[t_car];
            car_cost[t_car] += c;
            vis[t_car] = false;
        }
    }

    int last_m = change_to_min("23:59");
    for (int i = 0; i < 10000; i++) {
        if (vis[i]) {
            int c = last_m - car_time[i];
            car_cost[i] += c;
            car_time[i] = 0;
        }
    }

    for (int i = 0; i < 10000; i++) {
        if (car_cost[i] > 0) {
            int c = cost;
            int p_t = ceil((double)(car_cost[i] - m) / m_a);

            if (p_t > 0) c += p_t * cost_a;
            answer.push_back(c);
        }
    }

    return answer;
}