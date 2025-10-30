#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void multiply(vector<int>& a, int b) {
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int temp = a[i] * b + carry;
        a[i] = temp % 10;
        carry = temp / 10;
    }

    while (carry > 0) {
        a.push_back(carry % 10);
        carry /= 10;
    }
}


void add(vector<int>& sum, const vector<int>& factorial) {
    int carry = 0;
    int maxLen = max(sum.size(), factorial.size());


    while (sum.size() < maxLen) {
        sum.push_back(0);
    }

    for (int i = 0; i < maxLen; i++) {
        int temp = sum[i] + carry;
        if (i < factorial.size()) {
            temp += factorial[i];
        }
        sum[i] = temp % 10;
        carry = temp / 10;
    }

    if (carry > 0) {
        sum.push_back(carry);
    }
}

int main() {
    int n;
    cin >> n;


    vector<int> sum(1, 0);


    vector<int> factorial(1, 1);  // 1!

    for (int i = 1; i <= n; i++) {

        if (i > 1) {
            multiply(factorial, i);
        }


        add(sum, factorial);
    }


    for (int i = sum.size() - 1; i >= 0; i--) {
        cout << sum[i];
    }
    cout << endl;

    return 0;
}