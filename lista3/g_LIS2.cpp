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
	return a.first < b.first && a.second < b.second;
}

bool lower_cmp( set<pair<int, int>> a,  pair<int, int> b) {
	
	for (auto it = a.rbegin(); it != a.rend(); it++){
		// cout << (*it).first << " " << (*it).second << endl;
		if (cmp(*it,b)){
			return true;
		}
	}
	return false;
}


int lis(vector<pair<int, int> > & vet, int n){
	vector< set< pair<int, int> > > front(n);
	// for (int i = 1; i < n; i++){
	// 	front[i].insert(make_pair(_INF,_INF));
	// }
	front[0].insert(vet[0]);
	int res = 1;
	// cout << vet[0].first << " " << vet[0].second << " - -"<< endl;
	for (int i = 1; i < n; i++){
		// for (int j = 0; j < n; j++){
		// 	if (front[j].empty()) continue;
		// 	cout << "J: " << j << ": " ;
		// 	for (auto it = front[j].begin(); it != front[j].end(); it++)
		// 		cout << (*it).first << "," << (*it).second << " ";
		// 	cout << endl;
		// }
		auto pos = lower_bound(front.begin(), front.end(), vet[i], lower_cmp);
		if (pos == front.end()) continue;
		int index = pos - front.begin();
		for (auto it = front[index].begin(); it != front[index].end(); it++){
			// cout << (*it).first << " " << (*it).second << endl;
			if (cmp(vet[i], *it)){
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
	int n;
	scanf("%lld", &n);
	vector<pair<int, int> > vet(n);
	for (int i = 0; i < n; i++){
		scanf("%lld%lld", &vet[i].first, &vet[i].second);
	}
	int melhor = lis(vet, n);
	printf("%lld\n", melhor);
}
