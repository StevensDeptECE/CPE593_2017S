#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

constexpr double BIG = 1e30;

class MatrixGraph {
private:
	unsigned int V;
	vector<double> m;
public:
	MatrixGraph(unsigned int V) : V(V) {
		m.reserve(V*V);
		for (int i = 0; i < V*V; i++)
			m.push_back(BIG);
	}

	void setWeight(int from, int to, double w) {
		m[from*V + to] = w;
		m[to*V + from] = w;
	}

	double getWeight(int from, int to) const {
    return m[from * V + to];
	}
	void dfs(int v) {
		bool visited[V] = {false}; //O(V)
		dfs(v, visited);
	}

	// recursive way .. I like this better because we never call one that is already visited
	void dfs(int v, bool visited[]) {
		visited[v] = true;
		cout << v << ' ';
		for (int to = 0; to < V; to++) { //O(V)
			if (!visited[to] && getWeight(v, to) < BIG)
				dfs(to, visited);
		}
	}

	// slightly slower, we call, but immediately terminate
	void dfs2(int v, bool visited[]) {
		if (visited[v])
			return;
		visited[v] = true;
		cout << v << ' ';
		for (int to = 0; to < V; to++) {
			if (getWeight(v, to) < BIG)
				dfs(to, visited);
		}
	}

	void dfsIterative(int v) {
		bool visited[V] = {false}; //O(V)
		stack<int> verticesToDo; //O(1)
		visited[v] = true;
		verticesToDo.push(v);

		while (!verticesToDo.empty()) {
			v = verticesToDo.top();
			verticesToDo.pop();
			cout << v << ' ';
			for (int to = 0; to < V; to++) {
				if (!visited[to] && getWeight(v, to) < BIG) {
					visited[to] = true;
					verticesToDo.push(to);
				}
			}
		}
	}
	void bfsIterative(int v) {
		bool visited[V] = {false}; //O(V)
		queue<int> verticesToDo; //O(1)
		visited[v] = true;
		verticesToDo.push(v);

		while (!verticesToDo.empty()) {
			v = verticesToDo.front();
			verticesToDo.pop();
			cout << v << ' ';
			for (int to = 0; to < V; to++) {
				if (!visited[to] && getWeight(v, to) < BIG) {
					visited[to] = true;
					verticesToDo.push(to);
				}
			}
		}
	}
	
};

int main() {
	MatrixGraph g(5);
	g.setWeight(0,2, 0.0);
	g.setWeight(2,3, 0.0);
	g.setWeight(2,4, 0.0);
	g.setWeight(1,3, 0.0);
  g.dfs(0); // 02314
	cout << '\n';
	g.dfsIterative(0); // 02431
	cout << '\n';
	g.bfsIterative(0); // 02431
	cout << '\n';
}
