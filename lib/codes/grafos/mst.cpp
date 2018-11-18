struct edge{ int x, y, w; };

int find(int x, vi & uf){ return uf[x] == x ? x : find(uf[x], uf); }

void merge(int x, int y, vi & uf, vi & sz){
	x = find(x, uf); y = find(y, uf);
	if (sz[x] > sz[y]){ swap(x, y); }
	sz[y] += sz[x];
	uf[x] = uf[y];
}

signed main(){
	vector<edge> vet(m);
	// read edges and sort by weight
	vi uf(n), sz(n, 1);
	iota(uf.begin(), uf.end(), 0);
	int res = 0;
	for (int i = 0; i < m; i++){
		if (find(vet[i].x, uf) != find(vet[i].y, uf)){
			merge(vet[i].x, vet[i].y, uf, sz);
			res += vet[i].w;
		}
	}
}