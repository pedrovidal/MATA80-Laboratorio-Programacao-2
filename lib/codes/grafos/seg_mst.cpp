struct Edge{ int u, v, w; bool usable = true; };

int find(vi & uf, int x){ return uf[x] == x ? x : find(uf, uf[x]); }

void merge(vi & uf, vi & sz, int x, int y){
	x = find(uf, x); y = find(uf, y);
	if (sz[x] > sz[y]){ swap(x, y); }
	sz[y] += sz[x];
	uf[x] = uf[y];
}

pair<vi, int> mst(vector<Edge> & edges, vi uf, vi sz, int n){
	vi ids;
	int m = edges.size(), cost = 0;
	for (int i = 0; i < m; i++){
		if (edges[i].usable && find(uf, edges[i].u) != find(uf, edges[i].v)){
			merge(uf, sz, edges[i].u, edges[i].v);
			ids.push_back(i);
			cost += edges[i].w;
		}
	}
	return ids.size() == n - 1 ? make_pair(ids, cost) : make_pair(vi (), INF);  
}

signed main(){
	vi sz(n + 1, 1), uf(n + 1), mst_orig, dummy;
	iota(uf.begin(), uf.end(), 0);
	vector<Edge> edges(m);
	// read edges and sort by weight
	int cost_orig, second_best = INF, cost;
	tie(mst_orig, cost_orig) = mst(edges, uf, sz, n);
	if (cost_orig == INF){ cout << "No way" << endl; return 0; }
	for (int id : mst_orig){
		edges[id].usable = false;
		iota(uf.begin(), uf.end(), 0);
		sz.assign(n + 1, 1);
		tie(dummy, cost) = mst(edges, uf, sz, n);
		second_best = min(second_best, cost);
		edges[id].usable = true;
	}
	second_best == INF ? cout << "No second way" : cout << second_best; cout << endl;
}