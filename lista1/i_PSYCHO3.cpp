#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
#define INF INT_MAX
#define _INF INT_MIN
#define MAX 1123

bitset<MAX> psycho, vis, sieve;
vector<int> primes;

void calc_sieve(){
	sieve.set();
	sieve[0] = false;
	sieve[1] = false;
	for (int i = 2; i <= sqrt(MAX); i++){
		if (sieve[i]){
			for (int j = i * i;  j < MAX; j+= i){
				sieve[j] = false;
			}
			primes.push_back(i);
		}
	}
	for (int i = sqrt(MAX)+1; i < MAX; i++){
		if (sieve[i]){
			primes.push_back(i);
		}
	}
}

bool is_psycho(int x){
	if (vis[x]) return psycho[x];
	int par = 0, imp = 0;
	int num = x;
	for (int i = 0; num > 1 && i < primes.size(); i++){
		if (num % primes[i]) continue;
		int cont = 0;
		while(num % primes[i] == 0){
			cont++;
			num/=primes[i];
		}
		if (cont % 2 == 0) par++;
		else imp++;
	}
	// cout << x << " " << par << " " << imp << endl;
	psycho[x] = par > imp;
	vis[x] = true;
	return psycho[x];
}

signed main(){
	calc_sieve();
	// for (int i = 0; i < primes.size(); i++){
	// 	cout << primes[i] << endl;
	// }
	// return 0;
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> moeda;
		for (int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			// cout << psycho[1] << endl;
			if (is_psycho(x)){
				moeda.push_back(x);
				// cout << x << " is psycho" << endl;
			}
			// else{
			// 	cout << x << " is ordinary\n";
			// }
		}
		bitset<112345> dp, aux;
		dp[0] = true;
		for (int i = 0; i < (int)moeda.size(); i++){
			aux |= dp;
			aux <<= moeda[i];
			dp |= aux;
			
		}
		if (dp[k]) printf("Yes\n");
		else printf("No\n");
	}
}