#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF INT_MAX

// quantidade limitada - varre de tras p frente
// quantidade ilimitada - varre de frente p tras

signed main(){
	int n, m;
	while(cin >> m, m){
		cin >> n;
		vector<int> moeda(n), ultima(m + 1, 0);	
		for (int i = 0; i < n; i++){
			cin >> moeda[i];
		}
		vector<int> dp(m+1, INF);
		sort(moeda.begin(), moeda.end());
		dp[0] = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j <= m; j++){
				if (dp[j] == INF)
					continue;
				if (j + moeda[i] > m)
					break;
				if (dp[j] + 1 < dp[j + moeda[i]]){
					ultima[j + moeda[i]] = moeda[i];					
				}
				dp[j + moeda[i]] = min(dp[j] + 1, dp[j + moeda[i]]);							
			}
		}
		if (dp[m] == INF){
			cout << "Impossivel" << endl;		
		}
		else{
			//cout << "usei ";
			cout << dp[m] << endl;		
			//cout << " moedas:";
			//int i = m;			
			//while(i){
			//	cout << " " << ultima[i];
			//	i -= ultima[i];
			//}
			//cout << endl;
		}
	}
}