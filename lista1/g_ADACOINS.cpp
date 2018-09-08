#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main(){
	int n, q;
	scanf("%lld%lld", &n, &q);
	vector<int> coin(n);
	for (int i = 0; i < n; i++){
		scanf("%lld", &coin[i]);
	}
	bitset<100001> dp, aux;
	dp[0] = true;
	for (int i = 0; i < n; i++){
		aux |= dp;
		aux <<= coin[i];
		dp |= aux;
		// dp |= (dp << coin[i]);
	}
	vector<int> pre(100001, 0);
	pre[0] = 0;
	for (int i = 1; i < 100001; i++){
		pre[i] = pre[i-1] + dp[i];
	}
	for (int i = 0; i < q; i++){
		int l, r;
		scanf("%lld%lld", &l, &r);
		cout << pre[r] - pre[l-1] << endl;
	}
}