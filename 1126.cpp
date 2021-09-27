#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int M;
	vector<int> device;
	vector<int> ans;
	int k = 0;
	cin >> M;
	int t;
	auto it = 0;
	cin >> t;
	while (t != -1) {
		while (k != M) {
			device.push_back(t);
			cin >> t;
			k = k + 1;
		}
		auto max = max_element(device.begin(), device.end());
		ans.push_back(*max);
		device.erase(device.begin());
		k = k-1;
	}
	for (auto it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << endl;
	}
}
