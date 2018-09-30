#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

bool cmp(int a, int b){
	return a <= b;
}

bool cmp2(pair<int, int> a, pair<int, int> b){
	if (a.first == b.first){
		return a.second < b.second;
	}
	return a.first > b.first;
}

int lds(vector<pair<int, int>> & vet, int n){
	vector<int> lds(n + 1, INF);
	lds[0] = 0;
	int res = 0;
	for (int i = 0; i < n; i++){
		int pos = lower_bound(lds.begin(), lds.end(), vet[i].second, cmp) - lds.begin();
		// cout << "pos = " << pos << endl;
		if (pos == n + 1)
			continue;
		lds[pos] = vet[i].second;
		res = max(res, pos);
	}
	return res;
}

signed main(){
	int t;
	scanf("%lld", &t);
	while(t--){
		int n;
		scanf("%lld", &n);
		vector< map<int, int> > front(n);
		vector< pair<int, int> > vet(n);
		for (int i = 0; i < n; i++){
			scanf("%lld%lld", &vet[i].first, &vet[i].second);
		}
		sort(vet.begin(), vet.end(), cmp2);
		// cout << endl;
		// for (int i = 0; i < n; i++){
		// 	cout << vet[i].first << "," << vet[i].second << endl;
		// }
		cout << lds(vet, n) << endl;
	}
}
