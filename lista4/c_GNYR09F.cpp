#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define endl '\n'

int res(int a, int b){
	vector<vector<int>> dp0(a + 1, vector<int>(b + 1, 0)), dp1(a + 1, vector<int>(b + 1, 0));
	dp0[1][0] = 1;
	dp1[1][0] = 1;
	for (int i = 2; i <= a; i++){
		for (int j = 0; j <= b; j++){
			dp0[i][j] = dp0[i - 1][j] + dp1[i - 1][j];
			dp1[i][j] = dp0[i - 1][j] + (j ? dp1[i - 1][j - 1] : 0);
		}
	}
	return dp0[a][b] + dp1[a][b];
}

signed main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int cont = 1;
	for (int i = 0; i < n; i++){
			int t, a, b;
			cin >> t >> a >> b;
			cout << t << " " << res(a, b) << endl; 
	}
}