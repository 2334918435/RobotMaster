#include <iostream>
#include <vector>

using namespace std;

int main() {
    int l, m;
    cin >> l >> m;
    
    // 创建一个布尔数组，标记树是否需要被移除，初始都为false（不需要移除）
    vector<bool> removed(l + 1, false);
    
    // 处理每个区域，标记需要移除的树
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        for (int j = u; j <= v; ++j) {
            removed[j] = true;
        }
    }
    
    // 统计剩余的树的数量
    int count = 0;
    for (int i = 0; i <= l; ++i) {
        if (!removed[i]) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}