#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long N;
	int k;
	long long Q;
	int A[10];
	k = 0;
	Q = 0;
	cin >> N;
	if (N == 0) {
		Q = 10;
		cout << Q;
		return 0;
	}
	if (N == 1) {
		Q = N;
		cout << Q;
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		A[i] = 0;
	}
	for (int i = 9; i > 1; --i) {
		while (N % i == 0) {
			N = N / i;
			A[i] = A[i] + 1;
		}
	}
	for (int i = 0; i < 10; i++) {
		k=A[i]+k;
	}
	for (int i = 0; i < 10; i++) {
		if (A[i] != 0) {
			while (A[i] != 0) {
				Q = pow(10, k - 1) * i + Q;
				A[i] = A[i] - 1;
				k = k - 1;
			}
		}
	}
	if (N!=1) {
		Q = -1;
	}
	cout<< Q;
}
