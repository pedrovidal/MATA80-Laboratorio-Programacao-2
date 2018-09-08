#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
#define INF INT_MAX
#define _INF INT_MIN
#define MAX 12345


signed main(){
	int x, y, n, caso = 1;
	while(scanf("%d%d%d", &x, &y, &n), x+y+n){
		vector<int> moeda(n);
		int t = 0;
		printf("Teste %d\n", caso++);
		for (int i = 0; i < n; i++){
			scanf("%d", &moeda[i]);
			t += moeda[i];
		}
		bitset<MAX> dp, aux;
		dp[0] = true;
		for (int i = 0; i < n; i++){
			aux |= dp;
			aux <<= moeda[i];
			dp |= aux;
		}
		int dif = abs(x-y);
		bool f = false;
		for (int i = 0; !f && i < MAX; i++){
			if (dp[i] && dif + i == t - i){
				printf("S\n\n");
				f = true;
			}
		}
		if (!f){
			printf("N\n\n");
		}
	}
}