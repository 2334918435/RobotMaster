#include <iostream>
using namespace std;

int main() {
    int m, t, s;
    cin >> m >> t >> s;
    
    int result, eaten;
    
    if (t == 0) {
        // 如果吃苹果不需要时间，所有苹果都被吃完
        result = 0;
    } 
    else {
        // 计算在s分钟内能吃完多少个苹果
        if (s % t == 0) {
            eaten = s / t;
        } else {
            eaten = s / t + 1;
        }
    result = m - eaten;
        
        // 如果结果小于0，说明所有苹果都被吃完了
    if (result < 0) {
            result = 0;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
