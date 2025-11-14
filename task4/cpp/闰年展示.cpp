#include <iostream>
#include <vector>
using namespace std;

// 判断是否为闰年的函数
bool shirunnian(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int x, y;
    cin >> x >> y;
    
    vector<int> runnian;
    
    // 遍历区间中的所有年份
    for (int i = x; i <= y; i++) {
        if (shirunnian(i)) {
            runnian.push_back(i);
        }
    }
    
    // 输出闰年个数
    cout << runnian.size() << endl;
    
    // 输出所有闰年年份
    for (int i = 0; i < runnian.size(); i++) {
        if (i > 0) cout << " ";
        cout << runnian[i];
    }
    cout << endl;
    
    return 0;
}
