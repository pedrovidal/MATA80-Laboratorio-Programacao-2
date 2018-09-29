#include <bits/stdc++.h>
using namespace std;

bool lower_cmp( map<int, int> & a,  pair<int, int> b) {
	auto it = a.lower_bound(b.first);
	if (it == a.begin()) return false;
	it--;
	return it->second < b.second;
}

vector< map<int, int> > front(100001);

signed main(){
	int n;
	scanf("%d", &n);
	pair<int, int> aux;
	scanf("%d%d", &aux.first, &aux.second);
	front[0].insert(front[0].begin(), aux);
	int res = 1;
	for (int i = 1; i < n; i++){
		scanf("%d%d", &aux.first, &aux.second);
		int pos = lower_bound(front.begin(), front.begin() + res, aux, lower_cmp) - front.begin();
		auto lb = front[pos].lower_bound(aux.first);
		auto it = lb;
		while(it != front[pos].end() && aux.second <= it->second ){
			it++;
		}
		front[pos].erase(lb, it);
		front[pos].insert(it, aux);
		res = max(res, pos + 1);
	}
	printf("%d\n", res);
}
