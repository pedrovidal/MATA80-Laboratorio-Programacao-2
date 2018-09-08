#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
#define INF INT_MAX
#define _INF INT_MIN
#define MAX 3123

signed main(){
	int n, teste = 1;
	while(cin >> n, n){
		string s;
		cin >> s;
		cout << "Teste " << teste++ << endl;
		vector<vector<bool> > mat(n);
		for (int i = 0; i < n; i++){
			mat[i].resize(n, false);
			int l = i, r = i;
			while(l >= 0 && r < n && s[l] == s[r]){
				mat[l][r] = true;
				l--;
				r++;
			}
			l = i, r = i+1;
			while(l >= 0 && r < n && s[l] == s[r]){
				mat[l][r] = true;
				l--;
				r++;
			}
		}
		vector<int> dp(n+1, INF);
		dp[0] = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < i; j++){
				if (mat[j][i-1]){
					dp[i] = min(dp[i], dp[j]+1);
				}
			}
			// if (dp[i] == INF){
				// dp[i] = dp[i-1]+1;
			// }
			// cout << dp[i] << " ";
		}
		cout << dp[n] << endl << endl;
	}
}