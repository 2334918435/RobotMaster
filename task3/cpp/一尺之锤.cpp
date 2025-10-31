#include <iostream>
using namespace std;

int main() {
    int a,i=0;
    cin >> a;
    while (a != 1) {
        a = a / 2;
        i++;
    }
    cout << i + 1 << endl;
    return 0;
}