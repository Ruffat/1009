#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float x = 0;
	int N;
	float a0;
	float aNplusONE;
	float a1;
	cin >> N;
	cin >> a0;
	cin >> aNplusONE;
	float* c = new float[N];
	for (int i = 0; i < N; i++) {
		cin >> c[i];
	}
	for (int i = 0; i <N; i++) {
		x = (2 + 2 * (N - (i+1))) * c[i] + x;
	}
	a1 = (aNplusONE + N * a0 - x) / (N + 1);
	//cout <<a1;
	printf("%.2f\n", a1);

	delete[] c;
	return 0;
}
