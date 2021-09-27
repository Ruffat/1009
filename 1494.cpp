#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> balls;
	int N;
	int t, max = 0;
	cin >> N;
	int k = 1;

	while (k < N) {
		cin >> t;
		k = k + 1;
		for (int i = max + 1; i < t; i++) {
			balls.push_back(i);
		}
		if (t > max)
			max = t;
		else {
			if (balls.back() == t) {
				balls.pop_back();
			}
			else {
				cout << "Cheater";
				return 0;
			}
		}
	}
	cout << "Not a proof";
	return 0;
}
