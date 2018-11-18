#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define endl '\n'
#define ta a.size() + 1
#define tb b.size() + 1
#define DESYNC ios::sync_with_stdio(false)

int calc_lis(vi & vet, int n){
	vi lis(n + 1, INF);
	lis[0] = 0;
	int res = 0;
	for (int i = 0; i < n; i++){
		int pos = lower_bound(lis.begin(), lis.end(), vet[i])  - lis.begin();
		lis[pos] = vet[i];
		res = max(res, pos);
	}
	return res;
}

signed main(){
	DESYNC;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n;
		cin >> n;
		vector<int> vet(n);
		map<int, int> pos_id;
		for (int i = 0; i < n; i++){
			cin >> vet[i];
			pos_id[vet[i]] = i + 1;
		}
		for (int i = 0; i < n; i++){
			cin >> vet[i];
			vet[i] = pos_id[vet[i]];
		}
		cout << calc_lis(vet, n) << endl;
	}
}