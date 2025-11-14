#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // bool first = true;                  //第一次打印质数不添加空格
    for (int i = 0; i < n; i++) {
        if (isPrime(numbers[i])) {
            // if (!first) {
            //     cout << " ";
            // }
            cout << numbers[i] << " ";
            // first = false;          //以后都有空格
        }
    }
    cout << endl;

    return 0;
}
