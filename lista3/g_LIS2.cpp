#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

struct compare{
	bool operator() (const pair<int, int> & a, const pair<int, int> & b) const{
		return a.first < b.first && a.second < b.second;
	}
};

bool cmp( pair<int, int> a,  pair<int, int> b) {
	return !(a.first < b.first && a.second < b.second);
}

bool cmp2( set<pair<int, int>, compare> a,  pair<int, int> b) {
	return lower_bound(a.begin(), a.end(), b, cmp) != a.end();
}

bool cmp3( pair<int, int> a,  pair<int, int> b) {
	return a.first < b.first && a.second < b.second;
}

int lis(vector<pair<int, int> > & vet, int n){
	vector< set< pair<int, int>, compare > > front(n);
	// for (int i = 1; i < n; i++){
	// 	front[i].insert(make_pair(_INF,_INF));
	// }
	front[0].insert(vet[0]);
	int res = 1;
	// cout << vet[0].first << " " << vet[0].second << " - -"<< endl;
	for (int i = 1; i < n; i++){
		auto pos = lower_bound(front.begin(), front.end(), vet[i], cmp2);
		if (pos == front.end()) continue;
		int index = pos - front.begin();
		for (auto it = front[index].begin(); it != front[index].end(); it++){
			// cout << (*it).first << " " << (*it).second << endl;
			if (cmp3(*it, vet[i])){
				front[index].erase(it);
			}
		}
		front[index].insert(vet[i]);
		res = max(res, index + 1);
		// cout << vet[i].first << " " << vet[i].second << " " << index << " " << res << endl;
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int> > vet(n);
	for (int i = 0; i < n; i++){
		cin >> vet[i].first >> vet[i].second;
	}
	int melhor = lis(vet, n);
	cout << melhor << endl;
}
