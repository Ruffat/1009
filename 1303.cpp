#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct interval {
    int left;
    int right;
};
bool comp(interval a, interval b) {
    if (a.left < b.left) return true;
    else if (a.left > b.left) return false;
    else {
        if (a.right >= b.right) return true;
        else return false;
    }
}

int main() {
    int M;
    vector<interval> intervals;
    vector<interval> sol;
    interval tmp;
    int left_covered = 0;
    int right_covered = 0;

    cin >> M;
    cin >> tmp.left >> tmp.right;
    while (tmp.left!=0 || tmp.right!=0) {
        
        intervals.push_back(tmp);
        cin >> tmp.left >> tmp.right;
    }

    sort(intervals.begin(), intervals.end(), comp);

    for (auto it = intervals.begin(); it != intervals.end(); it++) {
        auto track = intervals.begin();
        bool flag = false;
        while ( it->left <= left_covered) {
            if (it->right >= right_covered) {
                right_covered = it->right;
                track = it;
                flag = true;
            }
            it++;
            if (it == intervals.end()){
                break;
            }
        }

        if (!flag) break;
        sol.push_back(*track);
        left_covered = right_covered;
        if (right_covered >= M) break;
        it--;
    }

    if (right_covered >= M) {
        cout << sol.size() << endl;
        for (auto it = sol.begin(); it != sol.end(); it++) {
            cout << it->left << " " << it->right << endl;
        }
    }
    else {
        cout << "No solution" << endl;
    }
    return 0;
}
