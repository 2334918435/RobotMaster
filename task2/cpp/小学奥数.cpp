#include<iostream>
// 填上你觉得需要的其他头文件
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        // 粘贴问题 1 的主函数代码，除了 return 0
        cout << "I love Luogu!";
    } else if (T == 2) {
        // 粘贴问题 2 的主函数代码，除了 return 0
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        // 请自行完成问题 3 的代码
        cout << 14 / 4 << endl;
        cout<< 14 / 4 * 4 << endl;
        cout<< 14 % 4 << endl;
    } else if (T == 4) {
        cout << fixed << setprecision(3) << 500.0 / 3 << endl;
    } else if (T == 5) {
        // 请自行完成问题 5 的代码
        cout << 480 / 32;
    } else if (T == 6) {
        // 请自行完成问题 6 的代码
        cout << sqrt(36+81);
    } else if (T == 7) {
        // 请自行完成问题 7 的代码
        int i = 100;
        cout << (i += 10) << endl;
        cout << (i -= 20) << endl;
        cout << (i=0) << endl;
    } else if (T == 8) {
        // 请自行完成问题 8 的代码
        int r = 5;
        double pi = 3.141593;
        cout << 2 * pi * r << endl;
        cout << pi * r * r << endl;
        cout << 4.0 / 3 * pi * r * r * r << endl;
    } else if (T == 9) {
        // 请自行完成问题 9 的代码
        int peaches = 1;
        for (int day = 3; day >= 1; day--) {
            peaches = (peaches + 1) * 2;
        }
        cout << peaches << endl;
    } else if (T == 10) {
        // 请自行完成问题 10 的代码
        cout << 9 << endl;
    } else if (T == 11) {
        // 请自行完成问题 11 的代码
        cout << 100.0 / 3 << endl;
    } else if (T == 12) {
        // 请自行完成问题 12 的代码
        // int i = ;
        // char aaa = ;
        cout << 'M' - 'A' + 1 << endl;
        cout << char('A' + 18 - 1) << endl;
    } else if (T == 13) {
        // 请自行完成问题 13 的代码
        double pi = 3.141593;
        double total = 4.0 / 3 * pi * (pow(4, 3) + pow(10, 3));
        cout << fixed << setprecision(0) << pow(total, 1.0 / 3) << endl;
    } else if (T == 14) {
        // 请自行完成问题 14 的代码
        cout << (50 < 70 ? 50 : 70) << endl;
    }
    return 0;
}
