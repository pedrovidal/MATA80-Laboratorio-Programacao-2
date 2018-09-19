#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

int calc_lis(vector<int> & vet, int ini, int fim, vector<int> & best){
	vector<int> lis(fim + 1, INF);
	lis[0] = 0;
	lis[1] = vet[ini];
	int res = 1;
	for (int i = ini; i < fim; i++){
		auto pos = lower_bound(lis.begin(), lis.end(), vet[i]);
		if (pos == lis.end()) continue;
		lis[pos - lis.begin()] = vet[i];
		best[i] = pos - lis.begin();
		res = max(res, best[i]);
	}
	return res;
}

signed main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n;
		cin >> n;
		vector<int> vet(n);
		vector<int> best(n, 0);
		map<int, int> pos_id;
		for (int i = 0; i < n; i++){
			cin >> vet[i];
			pos_id[vet[i]] = i + 1;
		}
		for (int i = 0; i < n; i++){
			cin >> vet[i];
			vet[i] = pos_id[vet[i]];
		}
		int res = calc_lis(vet, 0, n, best);
		cout << res << endl;
	}
}