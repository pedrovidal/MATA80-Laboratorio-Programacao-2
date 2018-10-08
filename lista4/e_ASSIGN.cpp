#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

signed main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool mat[n][n];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> mat[i][j];
			}
		}

		vector<int> dp(1 << (n + 1), 0);
		dp[0] = 1;
		for (int mask = 0; mask <= 1 << n; mask++){
			int bits = __builtin_popcount(mask);
			if (bits > n) continue;
			for (int j = 0; j < n; j++){
				if (mask & (1 << j)) continue;
				if (!mat[bits][j]) continue;
				dp[mask | (1 << j)] += dp[mask];
			}
		}
		cout << dp[(1 << n) - 1] << endl;
	}
}