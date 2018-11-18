vi p(n), v(n), dp(cap+1, _INF); dp[0] = 0;
// read weight (p) and value (v)
int res = 0;
for (int i = 0; i < n; i++){
	for (int j = cap; j >= 0; j--){
		if (dp[j] == _INF || j + p[i] > cap) continue;
		dp[j + p[i]] = max(dp[j + p[i]], dp[j] + v[i]);		
		res = max(res, dp[j + p[i]]);		
	}	
}