#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

int calc_lpis(vector<int> & vet, int n){
	map<int, int> best;
	int res = 0;
	for (int i = 0; i < n; i++){
		best[vet[i]] = max(best[vet[i]], best[vet[i] - 1] + 1);
		res = max(res, best[vet[i]]);
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> vet(n);
		for (int i = 0; i < n; i++){
			cin >> vet[i];
		}
		cout << n - calc_lpis(vet, n) << endl;
	}
}