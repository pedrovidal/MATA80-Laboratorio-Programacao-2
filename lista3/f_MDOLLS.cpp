#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

bool cmp(pair<int, int> a, pair<int, int> b){
	return !(a.first < b.first && a.second < b.second) && !(b.first < a.first && b.second < a.second);
}

bool cmp2(set<pair<int, int>> a, pair<int, int> b){
	return lower_bound(a.begin(), a.end(), b, cmp) != a.end();
}

int lis(vector<pair<int, int> > & vet, int n){
	vector<set<pair<int, int>>> front(n);
	front[0].insert(vet[0]);
	int res = 1;
	cout << vet[0].first << " " << vet[0].second << " - -" << endl;
	for (int i = 1; i < n; i++){
		auto pos = lower_bound(front.begin(), front.end(), vet[i], cmp2);
		if (pos == front.end()) continue;
		int index = pos - front.begin();
		front[index].insert(vet[i]);
		res = max(res, index + 1);
		cout << vet[i].first << " " << vet[i].second << " " << index + 1 << " " << res << endl;
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
		vector<pair<int, int> > vet(n);
		for (int i = 0; i < n; i++){
			cin >> vet[i].first >> vet[i].second;
		}
		// sort(vet.begin(), vet.end());
		int melhor = lis(vet, n);
		cout << melhor << endl;
	}
}