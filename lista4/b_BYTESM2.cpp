#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int> > mat(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> mat[i][j];
			}
		}
		vector<vector<int> > dp(n, vector<int>(m, 0));
		int res = 0;
		for (int j = 0; j < m; j++){
			dp[0][j] = mat[0][j];
			res = max(res, dp[0][j]);
		}
		for (int i = 1; i < n; i++){
			for (int j = 0; j < m; j++){
				int a = 0, b = 0, c = 0;
				if (j) a = dp[i - 1][j - 1];
				b = dp[i - 1][j];
				if (j + 1 < m) c = dp[i - 1][j + 1];
				dp[i][j] = mat[i][j] + max({a, b, c});
				res = max(res, dp[i][j]);
			}
		}
		cout << res << endl;
	}
}