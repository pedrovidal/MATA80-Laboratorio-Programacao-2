#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

int lis(vector<int> & vet, vector<int> & best, int n){
	vector<int> lis(n + 1, INF);
	lis[0] = 0;
	int res = 0;
	for (int i = 0; i < n; i++){
		auto pos = lower_bound(lis.begin(), lis.end(), vet[i]);
		if (pos == lis.end()) continue;
		int index = pos - lis.begin();
		lis[index] = vet[i];
		best[i] = index;
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
		set<int> res;
		int melhor = lis(vet, best, n);
		
		vector<int> aux(melhor + 2, 0);

		int i;

		for (i = n - 1; i >= 0; i--){
			if (best[i] == melhor){
				res.insert(vet[i]);
				aux[best[i]] = vet[i];
				break;
			}
		}

		for (; i>= 0; i--){
			if (aux[best[i] + 1] == 0 && best[i] == melhor){
				res.insert(vet[i]);
				aux[best[i]] = max(aux[best[i]], vet[i]);
			}
			else if (aux[best[i] + 1] > vet[i]){
				res.insert(vet[i]);
				aux[best[i]] = max(aux[best[i]], vet[i]);
			}
		}

		// for (int i = 0; i < n; i++){
		// 	cout << vet[i] << " " << best[i] << " " << pai[i] << endl;
		// }

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