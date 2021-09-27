#include <iostream>
#include <vector>
using namespace std;
vector< vector <long long> > stair(501, vector < long long >(501));
long long solution(int i, int j)
{
    if (i == 0) {
        return 1;
    }
    if (j == 0) {
        return 0;
    }

    if (stair[i][j] == -1)
    {
        stair[i][j] = solution(i, j - 1);
        if (i >= j) {
            stair[i][j] += solution(i - j, j - 1);
        }
            
    }
    return stair[i][j];

}


int main()
{
    long long N;
    cin >> N;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            stair[i][j] = -1;
        }
            
    }
    cout << solution(N, N - 1);
    return 0;
}
