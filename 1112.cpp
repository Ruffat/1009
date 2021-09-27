#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct interval {
	int left;
	int right;
};
int comp(interval a, interval b) {

	return (a.right < b.right);
}
int main() {
	vector<interval> intervals;
	interval tmp;
	int n;
	cin >> n;
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		if (l > r) {
			tmp.left = r;
			tmp.right = l;
		}
		else {
			tmp.left = l;
			tmp.right = r;
		}
		intervals.push_back(tmp);
	}
	sort(intervals.begin(), intervals.end(), comp);
	vector<interval> ans;
	for (auto it = intervals.begin(); it != intervals.end() - 1;) {
		if ((it + 1)->left < it->right) {

			if ((it + 2) == intervals.end()) {
				intervals.erase(it + 1);
				break;
			}
			intervals.erase(it + 1);

		}
		else {
			++it;
		}
	}
	cout << intervals.size() << endl;
	for (auto it = intervals.begin(); it != intervals.end(); ++it) {
		cout << it->left << " " << it->right << endl;
	}


	return 0;
}
