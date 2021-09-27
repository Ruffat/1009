#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N, K, sol;
    double S = 0, l=0,r, mid;
    double eps = 1e-9;
    cin >> N >> K;
    double* a = new double[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        S = S + a[i];
    }
    S = (S / K);
    r = S;
    while (r - l > eps) {
        sol = 0;
        mid = (l + r) / 2;
        for (int i = 0; i < N; i++) {
            sol += (int)(a[i] / mid);
        }
        if (sol >= K) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    printf("%.2f\n", floor(r * 100) / 100);
}
