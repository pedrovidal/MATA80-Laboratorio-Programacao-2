struct Grafo{ vvi adj(n), cost(n); vi dist(n, INF); };

int dijkstra(int s, int t, Grafo g){
	g.dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(g.dist[s], s);
	while(!pq.empty()){
		int d, u;
		tie(d, u) = pq.top(); pq.pop();
		for (int i = 0; i < g.adj[u].size(); i++){
			int v = g.adj[u][i], w = g.cost[u][i];
			if (d + w < g.dist[v]){
				g.dist[v] = d + w;
				pq.emplace(g.dist[v], v);
			}
		}
	}
	return g.dist[t] == INF ? -1 : g.dist[t];
}