#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

signed main(){
	int n;
	cin >> n;
	vector<int> vet(n);
	for (int i = 0; i < n; i++){
		cin >> vet[i];
	}
	vector<int> lis(n + 1, INF);
	vector<int> pai(n + 1, -1);
	int res = 0;
	lis[0] = 0;
	lis[1] = vet[0];
	for (int i = 1; i < n; i++){
		auto pos = lower_bound(lis.begin(), lis.end(), vet[i]);
		if (pos == lis.end()) continue;
		lis[pos - lis.begin()] = vet[i];
	}
	for (int i = 0; i < n+1; i++){
			if (lis[i] == INF){
				cout << i - 1 << endl;
				return 0;
			}
	}
	cout << n << endl;
}