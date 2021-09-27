#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct interval {
	int left;
	int right;
	int num;
};

int main() {
	int n, m;
	vector<interval> intervals;
	vector<int> points;
	interval tmp;
	int l, r, p;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
			intervals.push_back({ l,r,i + 1 });
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> p;
		points.push_back(p);
	}
	
	vector<interval> ans;
	auto ip = intervals.begin();
	for (auto it = points.begin(); it != points.end(); ++it) {
		while (true) {
			while ( ans.size()>0 && (ans.end()-1)->right < *it) {
				ans.pop_back();
			}
			while ( ip!=intervals.end() && ip->left <= *it) {
				ans.push_back(*ip);
				ip++;
			}
			if (ans.size()==0) {
				cout << -1 << endl;
				break;
			}
			else if ((ans.end()-1)->right >= *it) {
				cout << (ans.end()-1)->num << endl;
				break;
			}
		}
	}
	return 0;

}
