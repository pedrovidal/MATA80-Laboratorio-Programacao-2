#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF INT_MIN

// quantidade limitada - varre de tras p frente
// quantidade ilimitada - varre de frente p tras

signed main(){
	int c, f, t = 1;
	while(cin >> c >> f, c + f){
		vector<int> p(f), v(f);
		for (int i = 0; i < f; i++){
			cin >> p[i] >> v[i];		
		}
		vector<int> dp(c+1, INF);
		dp[0] = 0;
		int res = 0;			
		for (int j = 0; j < f; j++){
			for (int i = c; i >= 0; i--){
				if (dp[i] == INF)
					continue;
				if (i + p[j] > c)
					continue;
				dp[i + p[j]] = max(dp[i + p[j]], dp[i] + v[j]);		
				res = max(res, dp[i + p[j]]);			
			}
		}
		cout << "Teste " << t++ << endl;
		cout << res << endl << endl;
	}
}