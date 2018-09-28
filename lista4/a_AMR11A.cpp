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
		// mat[0][0] = INF;
		dp[n-1][m-1] = mat[n-1][m-1];
		for (int j = m - 2; j >= 0; j--){
			dp[n - 1][j] = min(mat[n - 1][j], dp[n - 1][j + 1] + mat[n - 1][j]);
		}
		for (int i = n - 2; i >= 0; i--){
			dp[i][m - 1] = min(mat[i][m - 1], dp[i + 1][m - 1] + mat[i][m - 1]);
		}
		for (int j = m - 2; j >= 0; j--){
			for (int i = n - 2; i >= 0; i--){
				dp[i][j] = min(mat[i][j], mat[i][j] + max(dp[i][j+1], dp[i+1][j]));
			}
		}
		// for (int i = 0; i < n; i++){
		// 	for (int j = 0; j < m; j++){
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		cout << abs(dp[0][0]) + 1 << endl;
		// cout << dp[0][0] << endl;
	}
}