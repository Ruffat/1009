#include <iostream>
#include <vector>
using namespace std;
#define eps 1000000009
int is_prime_number(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i)
			continue;
		return 0;
	}
	return 1;
}
vector<int> prime_number(1000);
//int numbers[10010][100] = { {0} };
vector< vector <int> > numbers(10010, vector <int>(100, 0));
int solution(int N) {

	int tmp;
	int answer = 0;
	for (int i = 4; i <= N; i++) {
		for (int j = 11; j < 100; j += 2) {
			for (int k = 1; k < 10; k += 2) {
				tmp = j * 10 + k;
				if (prime_number[tmp]) {
					numbers[i][tmp % 100] += numbers[i - 1][j];
					numbers[i][tmp % 100] %= eps;
				}
			}
		}
	}


	for (int i = 0; i < 100; i++) {
		answer += numbers[N][i];
		answer %= eps;
	}

	return answer;
}

int main() {
	int n;
	cin >> n;
	for (int i = 100; i < 1000; i++) {
		if (is_prime_number(i)) {
			prime_number[i] = 1;
			numbers[3][i % 100]++;
		}
	}
	int otvet = solution(n);
	cout << otvet;
	return 0;
}
