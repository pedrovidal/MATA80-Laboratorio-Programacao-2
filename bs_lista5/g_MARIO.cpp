#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define endl '\n'

signed main(){
	ios::sync_with_stdio(false);
	int n, l;
	while(cin >> l >> n, n + l){
		vi vet(n);
		for(int i = 0; i < n; i++){
			cin >> vet[i];
		}
		int res = INF;
		for (int i = 0; i < n; i++){
			int x = vet[i] + l - 1;;
			// cout << vet[i] << " " << x << " ";
			int pos = lower_bound(vet.begin(), vet.end(), x) - vet.begin();
			if (pos > n) continue;
			int falta = l - (pos - i) - 1;
			if (vet[pos] != x) falta++;
			// cout << pos << " " << vet[pos] << " " << falta << endl;
			res = min(res, falta);
		}
		cout << res << endl;
	}
}