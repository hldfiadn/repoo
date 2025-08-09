#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, kali;
    cin >> n >> kali;

    double rataan=0;
    int count=0;

    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;

        if (i % kali == 0) {
            rataan = rataan + x;
            count++;
        }
    }

    if (n==0 || kali==0 || kali>n) {
        cout << setprecision(2) << fixed << rataan;
    }
    else {
        rataan = rataan/(n/kali);
        cout << setprecision(2) << fixed << rataan;
    }


  return 0;
}