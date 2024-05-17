#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Graph {
public:
	vector<vector<int>> graph;
	vector<int> visited;
	vector<int> match;
	Graph (int v_num) {
		graph.resize(v_num);
		visited.resize(v_num);
		match.resize(v_num);
		fill(match.begin(), match.end(), -1);
	}
	void fill_graph() {
		ifstream in;
		in.open("test.txt");
		int a, b;
		while (in >> a && in >> b) {
			a--;
			b--;
			graph[a].push_back(b); //a принадлежит левой доле, b - правой
		}
	}
	bool dfs(int v) {
		if (visited[v]) {
			return false;
		}
		visited[v] = 1;
		for (int u : graph[v]) {
			if (match[u] == -1 || dfs(match[u])) {
				match[u] = v;
				return true;
			}
		}
		return false;
	}
	int Kuhn() {
		int max = 0;
		fill(visited.begin(), visited.end(), 0);
		for (int i = 0; i < graph.size(); i++) {
			if (dfs(i)) {
				max++;
			}
		}
		return max;
	}
};
int main() {
	int v_num;
	cin >> v_num;
	Graph A(v_num);
	A.fill_graph();
	cout << A.Kuhn();
	return 0;
}