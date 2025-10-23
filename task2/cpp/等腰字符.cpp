#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2 - i; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
