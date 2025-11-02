#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums;
    int num;

    while (cin >> num && num != 0) {
        nums.push_back(num);
    }

    reverse(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << nums[i];
    }
    cout << endl;

    return 0;
}