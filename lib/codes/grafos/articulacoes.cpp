struct Grafo{
	vvi adj;
	vi low, d, pai;
	vector<bool> vis;
	set<int> articulations;
	int tempo = 0;

	Grafo(int n){
		adj.resize(n);
		low.resize(n, INF);
		d.resize(n, INF);
		pai.resize(n, INF);
		vis.resize(n, false);
	}
};

int dfs(int u, Grafo & g, bool root){
	g.tempo++;
	g.d[u] = g.low[u] = g.tempo;
	g.vis[u] = true;
	int cont = 0;
	for (int v : g.adj[u]){
		if (!g.vis[v]){
			cont++;
			g.pai[v] = u;
			dfs(v, g, false);
			if (!root && g.low[v] >= g.d[u]){
				g.articulations.insert(u);
			}
			g.low[u] = min(g.low[u], g.low[v]);
		}
		else if (g.pai[u] != v){
			g.low[u] = min(g.low[u], g.d[v]);
		}
	}
	return cont;
}

signed main(){
	Grafo g = Grafo(n);
	// read edges and fill g.adj
	for (int i = 0; i < n; i++){
		if (!g.vis && dfs(i, g, true) > 1){
			g.articulations.insert(i);
		}
	}
}