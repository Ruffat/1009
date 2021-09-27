# 1009
#include <iostream>
using namespace std;

int main()
{
    long int n, k, i;
    //long int a[200];
    cin >> n;
    cin >> k;
    long int* arr = new long int[n];
    arr[0] = 1;
    arr[1] = k - 1;
    for (int i = 2; i <= n; i++) {
        arr[i]= (arr[i - 1] + arr[i - 2]) * (k - 1);
    }
    cout << arr[n];
    
}
