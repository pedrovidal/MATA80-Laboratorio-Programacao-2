void dfs(int u, vvi & adj, vector<bool> & vis, vector<pii> & res, int & tempo, vi & low, vi & d, vi & pai){
	tempo++;
	d[u] = low[u] = tempo;
	vis[u] = true;
	for (int v : adj[u]){
		if (!vis[v]){
			pai[v] = u;
			dfs(v, adj, vis, res, tempo, low, d, pai);
			if (low[v] > d[u]){
				res.emplace_back(min(u, v), max(u, v));
			}
			low[u] = min(low[u], low[v]);
		}
		else if (pai[u] != v){
			low[u] = min(low[u], d[v]);
		}
	}
}

signed main(){
	vvi adj(n);
	vector<bool> vis(n, false);
	vector<pii> res;
	vi low(n, INF), d(n, INF), pai(n, INF);
	// read edges and fill adj
	int tempo = 0;
	for (int i = 0; i < n; i++){
		if (!vis[i]){ dfs(i, adj, vis, res, tempo, low, d, pai); }
	}
}