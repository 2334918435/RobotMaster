#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    
    if (x == 1) {
        cout << "Today, I ate 1 apple." << endl;
    } else {
        cout << "Today, I ate " << x << " apples." << endl;
    }
    
    return 0;
}
