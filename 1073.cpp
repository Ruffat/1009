#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
    long long N;
    cin >> N;
    int mass[60001];
    mass[0] = 0;
    for (int i = 1; i <= N; i++) {
        mass[i] = i;
        for (int j = 0; j*j <= i; j++) {
            mass[i] = min(mass[i], mass[i - j * j] + 1);
        }
    }
    cout << mass[N];
    return 0;
}
