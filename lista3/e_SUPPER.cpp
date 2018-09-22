#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

int lis(vector<int> & vet, vector<int> & best, vector<int> & pai, int n){
	vector<int> lis(n + 1, INF);
	vector<int> lis_id(n + 1, INF);
	lis[0] = 0;
	lis_id[0] = -1;
	int res = 0;
	for (int i = 0; i < n; i++){
		auto pos = lower_bound(lis.begin(), lis.end(), vet[i]);
		if (pos == lis.end()) continue;
		int index = pos - lis.begin();
		lis[index] = vet[i];
		lis_id[index] = i;
		best[i] = index;
		pai[i] = lis_id[index - 1];
		res = max(res, best[i]);
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	int t = 10;
	while(t--){
		int n;
		cin >> n;
		vector<int> vet(n);
		for (int i = 0; i < n; i++){
			cin >> vet[i];
		}
		vector<int> best(n + 1, 0);
		vector<int> pai(n + 1, -1);
		set<int> res;
		int melhor = lis(vet, best, pai, n);
		for (int i = n - 1; i >= 0; i --){
			if (best[i] == melhor){
				int id = i;
				while(id > 0){
					res.insert(vet[id]);
					id = pai[id];
				}
			}
		}
		for (int i = 0; i < n; i++){
			cout << vet[i] << " " << best[i] << " " << pai[i] << endl;
		}
		cout << res.size() << endl;
		bool f = false;
		for (int i : res){
			if (f) cout << " ";
			cout << i;
			f = true;
		}
		cout << endl;
	}
}