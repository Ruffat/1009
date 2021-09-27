#include <iostream>
#include <vector>
#include <math.h>
#define MAX 50001
using namespace std;


vector<pair<int, int> > A[MAX];
int t_in[MAX], t_out[MAX], interval[MAX];
int ancestor[MAX][20];
int t = 0, j=0;

void DFS(int v, int z = 0, int l = 0) {
	int i1, i2;
	t_in[v] = t++;
	ancestor[v][0] = z; interval[v] = l;
	for (i1 = 1; i1 <= j; i1++) {
		ancestor[v][i1] = ancestor[ancestor[v][i1 - 1]][i1 - 1];
	}
	for (i1 = 0; i1 < A[v].size(); i1++) {
		i2 = A[v][i1].first;
		if (i2 != z) DFS(i2, v, l + A[v][i1].second);
	}
	t_out[v] = t++;
}
int parent(int x, int y) {
	return ((t_in[x] <= t_in[y]) && (t_out[x] >= t_out[y]));
}
int LCA(int x, int y) {
	if (parent(x, y)) {
		return x;
	}
	if (parent(y, x)) {
		return y;
	}
	for (int i = j; i >= 0; i--) {
		if (!parent(ancestor[x][i], y)) {
			x = ancestor[x][i];
		}
	}
	return ancestor[x][0];
}

int main() {
	int n;
	cin >> n;
	j = floor(log(n) / log(2));
	int u, v, w;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> w;
		A[u].push_back(make_pair(v, w));
		A[v].push_back(make_pair(u, w));
	}
	int m;
	cin >> m;
	DFS(0);
	int ans, lca;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		lca = LCA(u, v);
		ans = interval[u] - interval[lca] + interval[v] - interval[lca];
		cout << ans << endl;
	}
	return 0;
}
