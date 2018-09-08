#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF INT_MAX

// quantidade limitada - varre de tras p frente
// quantidade ilimitada - varre de frente p tras

signed main(){
	int n, t = 1;
	while(cin >> n){
		vector<int> moeda(n);
		bool f = true;
		for (int i = 0; i < n; i++){
			cin >> moeda[i];
			if (i && moeda[i - 1] >= moeda[i]) f = false;
		}
		cout << "Case #" << t++ << ":";
		for (int i = 0; i < n; i++){
			cout << " " << moeda[i];	
		}
		cout << endl;
		int val = moeda[n-1];
		vector<int> dp(val + 1, INF);
		dp[0] = 0;
		for (int i = 0; i < n; i++){
			if (dp[moeda[i]] != INF){
				f = false;
				break;
			}		
			for (int j = val; j >= 0; j--){
				if (dp[j] == INF)
					continue;
				if (j + moeda[i] > val)
					continue;
				dp[j + moeda[i]] = min(dp[j + moeda[i]], dp[j] + 1);	
			}
		}
		cout << "This is ";
		if (!f) cout << "not ";
		cout << "an A-sequence.\n";
	}
}