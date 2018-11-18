vi dp(m + 1, INF), coins(n), ultima(m + 1, 0); dp[0] = 0;
// read and sort coins
// bitset<100001> dp; dp[0] = true // solucao bitset
for (int i = 0; i < n; i++){
	// dp |= (dp << coin[i]); // solucao bitset
	for (int j = 0; j <= m && j + coins[i] <= m; j++){ // moedas ilimitadas
	// for (int j = m; j >= 0; j--){ //moedas limitadas
		if (dp[j] + 1 < dp[j + moeda[i]]) ultima[j + moeda[i]] = moeda[i];
		dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
	}
}
dp[m] == INF ? cout << "Impossivel" :  cout << dp[m]; cout << endl;