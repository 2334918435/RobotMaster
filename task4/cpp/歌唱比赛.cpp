#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 

    double max_score = -1; // 全局最高分初始化


    for (int i = 0; i < n; ++i) {
        int sum = 0;           // 该参赛者所有评分的总和
        int max_point = INT_MIN; // 最高分初始化值设为最小的常数
        int min_point = INT_MAX; // 同上

        // 读取该参赛者的 m 个评分
        for (int j = 0; j < m; ++j) {
            int score;
            cin >> score;

            sum += score;

            if (score > max_point) max_point = score;
            if (score < min_point) min_point = score;
        }


        double average = (double)(sum - max_point - min_point) / (m - 2);

        // 更新全局最高分
        if (average > max_score) {
            max_score = average;
        }
    }


    cout << fixed << setprecision(2) << max_score << endl;

    return 0;
}
//
// Created by 23349 on 2025/11/13.
//