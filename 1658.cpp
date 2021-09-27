#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_SUM = 900;
const int MAX_SQUARE = 8100;

short  deep[MAX_SUM + 1][MAX_SQUARE + 1];
short digital[MAX_SUM + 1][MAX_SQUARE + 1];

int main() {

    deep[0][0] = 1;
    digital[0][0] = 0;

    for (int sum = 1; sum <= MAX_SUM; sum++) {
        for (int sum_sq = 1; sum_sq <= MAX_SQUARE; sum_sq++) {
            for (int k = 1; k <= 9; k++) {
                if (sum >= k && sum_sq >= k * k && deep[sum - k][sum_sq - k * k]) {
                    if (deep[sum][sum_sq] == 0 || deep[sum][sum_sq] > 1 + deep[sum - k][sum_sq - k * k]) {
                        deep[sum][sum_sq] = 1 + deep[sum - k][sum_sq - k * k];
                        digital[sum][sum_sq] = k;
                    }
                }
            }
        }
    }

    int n; cin >> n;
    vector<int> ans;
    while (n--) {
        int sum, sum_sq;
        cin >> sum >> sum_sq;
        ans.clear();
        if (!deep[sum][sum_sq] || sum > MAX_SUM || sum_sq > MAX_SQUARE) {
            cout << "No solution" << endl;
        }
        else {

            while (sum != 0 && sum_sq != 0) {
                int k = digital[sum][sum_sq];
                ans.push_back(k);
                sum -= k;
                sum_sq -= k * k;
                if (ans.size() > 100) {
                    break;
                }
            }
            if (ans.size() > 100) {
                cout << "No solution" << endl;
            }
            else {
                for (auto it = ans.begin(); it != ans.end(); ++it) {
                    cout << *it;
                }
                cout << endl;
            }
        }
    }
    return 0;
}
