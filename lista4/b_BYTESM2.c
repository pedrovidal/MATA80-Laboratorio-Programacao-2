#include <stdio.h>

#define INF INT_MAX
// #define int long long
#define max(a,b) (a > b ? a : b)

// int max(int a, int b){
// 	if (a > b) return a;
// 	return b;
// }

signed main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d%d", &n, &m);
		int mat[n][m];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				scanf("%d", &mat[i][j]);
			}
		}
		int dp[n][m];
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
				dp[i][j] = mat[i][j] + max(max(a, b), c);
				res = max(res, dp[i][j]);
			}
		}
		printf("%d\n", res);
	}
}