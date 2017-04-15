class EdgeListGraph {
private:
	class Edge {
	public:
		double w;
		int to;
	};
  vector< LinkedList<Edge> > edges;
public:
	EdgeListGraph(int V) {
		edges.reserve(V);
	}
	void add(double w, int from, int to) {
		//TODO: Check for edge already here!!!
		edges[from].addFirst(Edge(w, to)   );
	}

	bool isAdjacent(int i, int j) {
		for (LinkedList<Edge>::iterator k = edges[i].begin(); k != edges[i].end(); ++i) { //O(V)
      if (k->to == j)
				return true;
		}
		return false;
	}

	void DFS(int v) {
		vector<int> todo;
		todo.push_back(v);
    vector<bool> visited;
		visited.reserve(V);
		visited[v] = true;
		while (!v.empty()) {
      v = todo.pop_back();
			for (int i = 0; i < V; i++)
				if (isAdjacent(v, i) && visited[v] == false) {
					visited[i] = true;
					todo.push_back(i);
				}
		}

	}

};
