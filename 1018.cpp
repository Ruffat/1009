#include <iostream>
#include <vector>

#define MAX 105
using namespace std;

struct Node {
	int num, apples;
	Node(int num, int apples) : num(num), apples(apples) {}
};
vector<Node> tree[MAX];
int sum[MAX], tree_answer[MAX][MAX];
bool visited[MAX][MAX];

int solver(int root, int branches) {
	if (visited[root][branches]) {
		return tree_answer[root][branches];
	}
	if (branches == 0) {
		return 0;
	}
	if (branches == 1) {
		return sum[root];
	}
	if (tree[root].size() == 0) {
		return sum[root];
	}
	if (tree[root].size() == 1) {
		return sum[root] + solver(tree[root][0].num, branches - 1);
	}

	Node left = tree[root][0];
	Node right = tree[root][1];

	int maxx = 0;
	for (int i = 0; i <= branches - 1; i++) {
		int tmp = sum[root] + solver(left.num, i) + solver(right.num, branches - 1 - i);
		if (maxx < tmp) {
			maxx = tmp;
		}
	}

	visited[root][branches] = true;
	tree_answer[root][branches] = maxx;
	return tree_answer[root][branches];
}
void dfs(int root, int parent) {
	for (int i = 0; i < tree[root].size(); i++) {
		Node node = tree[root][i];
		if (node.num != parent) {
			dfs(node.num, root);
			sum[node.num] = node.apples;
		}
		else {
			tree[root].erase(tree[root].begin() + i);
			i--;
		}
	}
}



int main() {
	int n, q;
	cin >> n >> q;
	int branch_num1, branch_num2, apples;
	for (int i = 0; i < n - 1; i++) {
		cin >> branch_num1 >> branch_num2 >> apples;
		tree[branch_num2].push_back(Node(branch_num1, apples));
		tree[branch_num1].push_back(Node(branch_num2, apples));
	}
	dfs(1, -1);
	cout << solver(1, q + 1) << endl;
	return 0;
}
