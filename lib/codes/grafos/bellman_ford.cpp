void bellman_ford(vector<tuple<int, int, int>> edges, int n, int s){
	vector<int> dist(n, INF);
	dist[s] = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < edges.size(); j++){
			int u = get<0>(edges[j]), v = get<1>(edges[j]), w = get<2>(edges[j]);
			dist[v] = min(dist[v], dist[u] + w);
		}
	}
	bool has_negative_cycle = false;
	for (int j = 0; j < edges.size(); j++){
		int u = get<0>(edges[j]), v = get<1>(edges[j]), w = get<2>(edges[j]);
		if (dist[v] > dist[u] + w){
			has_negative_cycle = true;
		}
	}
}