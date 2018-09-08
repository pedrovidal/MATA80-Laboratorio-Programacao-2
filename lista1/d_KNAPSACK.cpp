#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF INT_MIN

// quantidade limitada - varre de tras p frente
// quantidade ilimitada - varre de frente p tras

signed main(){
	int c, n;
	cin >> c >> n;
	vector<int> p(n), v(n);
	for (int i = 0; i < n; i++){
		cin >> p[i] >> v[i];	
	}
	vector<int> dp(c+1, INF);
	dp[0] = 0;
	int res = 0;
	for (int i = 0; i < n; i++){
		for (int j = c; j >= 0; j--){
			if (dp[j] == INF)
				continue;
			if (j + p[i] > c)
				continue;
			dp[j + p[i]] = max(dp[j + p[i]], dp[j] + v[i]);		
			res = max(res, dp[j + p[i]]);		
		}	
	}
	cout << res << endl;
}