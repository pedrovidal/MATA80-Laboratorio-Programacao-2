void dfs(int u, vvi & adj, vector<bool> & vis, vi & vet){
	vis[u] = true;
	for (int v : adj[u]){
		if (!vis[v]){
			dfs(v, adj, vis, vet);
		}
	}
	vet.push_back(u);
}

signed main(){
	vvi adj(n), adjT(n), scc;
	vector<bool> vis(n, false);
	vi ordem_vis;
	// read edges and fill adj & adjT
	for (int i = 0; i < n; i++){
		if (!vis[i]){ dfs(i, adj, vis, ordem_vis); }
	}
	vis.assign(n, false);
	for (int i = n - 1; i >= 0; i--){
		if (!vis[ordem_vis[i]]){
			scc.push_back(vi());
			dfs(ordem_vis[i], adjT, vis, scc[scc.size()-1]);
		}
	}
}