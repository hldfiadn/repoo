#include <iostream>
using namespace std;

int main () {
    int n, m;
    int x;
    int *arr;

    cin >> m >> n;

    arr = (int*) malloc((m+n) * sizeof(int));
    
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<m; i++) {
        cin >> arr[i+n];
    }

    for (int i=0; i < m+n; i++) {
        for (int j= i+1; j < m+n; j++) {
            if (arr[i] > arr[j]) {
                x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }
    }

    for (int i=0; i < m+n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}