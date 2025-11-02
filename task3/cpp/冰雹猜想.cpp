#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> sequence;

    while (true) {
        sequence.push_back(n);
        if (n == 1) break;
        if (n % 2 == 1) {
            n = n * 3 + 1;  
        } else {
            n = n / 2;      
        }
    }

    reverse(sequence.begin(), sequence.end());
    
    for (int i = 0; i < sequence.size(); ++i) {
        if (i > 0) cout << " ";
        cout << sequence[i];
    }
    cout << endl;
    
    return 0;
}