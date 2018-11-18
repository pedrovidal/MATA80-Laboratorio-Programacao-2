struct Grafo{
	vvi adj, cost, usable, pai;
	vi dist;
	Grafo(int n){
		adj.resize(n);
		cost.resize(n);
		usable.resize(n);
		dist.resize(n, INF);
		pai.resize(n);
	}
	void clean(int n){
		dist.assign(n, INF);
		pai = vvi (n, vi());
	}
};

int dijkstra(int s, int t, Grafo & g){
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	g.dist[s] = 0;
	pq.emplace(g.dist[s], s);
	while(!pq.empty()){
		int d, u;
		tie(d, u) = pq.top();
		pq.pop();
		if (u == t){
			break;
		}
		for (int i = 0 ; i < g.adj[u].size(); i++){
			if (!g.usable[u][i]){
				continue;
			}
			int v = g.adj[u][i];
			int w = g.cost[u][i];
			if (g.dist[v] >= g.dist[u] + w){
				if (g.dist[v] > g.dist[u] + w) g.pai[v].clear();
				g.pai[v].push_back(u);
				g.dist[v] = g.dist[u] + w;
				pq.emplace(g.dist[v], v);
			}
		}
	}
	if (g.dist[t] == INF) return -1;
	return g.dist[t];
}

void dfs(int t, int s, Grafo & g){
	if (t == s) return;
	for (int u : g.pai[t]){
		for (int i = 0; i < g.adj[u].size(); i++){
			if (g.adj[u][i] == t){
				g.usable[u][i] = 0;
				dfs(u, s, g);
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	int n, m;
	while(cin >> n >> m, n+m){
		int s, t;
		cin >> s >> t;
		Grafo g = Grafo(n);
		for (int i = 0 ; i < m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			g.adj[u].push_back(v);
			g.usable[u].push_back(1);
			g.cost[u].push_back(w);
		}
		int ini = dijkstra(s, t, g);
		if (ini == -1){
			cout << -1 << endl;
			continue;
		}
		dfs(t, s, g);
		g.clean(n);
		cout << dijkstra(s, t, g) << endl;
	}
}