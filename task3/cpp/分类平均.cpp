#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n,k,t1 = 0,t2 = 0,n1 = 0;
    cin>>n>>k;
    for (int i = 1; i <= n; i++) {
        if (i%k==0) {
            t1 += i;
            n1 ++;
        }
        else {
            t2 += i;
        }
    }
    cout << fixed << setprecision(1) << double (t1) / n1 << " " << double (t2) / (n - n1) << endl;
    return 0;
}