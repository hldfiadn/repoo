#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    int m, n, temp;
    int *arr;
    cin >> m >> n;
    arr = (int *) malloc((m+n) * sizeof(int));
    for (int i = 0; i < (m+n); i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < (m+n); i++)
    {
        for (int j = i+1; j < (m+n); j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < (m+n); i++)
    {
        cout << arr[i] << " ";
    }
}