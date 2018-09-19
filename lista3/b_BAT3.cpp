#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

int calc_lis(vector<int> & vet, int ini, int fim, vector<int> & best){
	vector<int> lis(fim + 1, INF);
	lis[0] = _INF;
	lis[1] = vet[ini];
	for (int i = ini; i < fim; i++){
		auto pos = lower_bound(lis.begin(), lis.end(), vet[i]);
		if (pos == lis.end()) continue;
		lis[pos - lis.begin()] = vet[i];
		best[i] = pos - lis.begin();
	}
	int res = 1;
	for (int i = 0; i <= fim; i++){
			if (lis[i] != INF){
				res = i;
			}
	}
	return res;
}

signed main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n, m;
		cin >> n >> m;
		vector<int> vet(n);
		vector<int> best(n, 0);
		for (int i = 0; i < n; i++){
			cin >> vet[i];
			vet[i] = -vet[i];
		}
		int res = calc_lis(vet, 0, n, best);
		int robin = best[m];
		res = max(res, robin + calc_lis(vet, m + 1, n, best));
		cout << res << endl;
	}
}