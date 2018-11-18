#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX
#define _INF LLONG_MIN
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define endl '\n'
#define x first
#define y second

double bs(pii old, pii at, int vs, int vc, double tempo){

}

signed main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pii> vet(n);
	for (int i = 0; i < n; i++){
		cin >> vet[i].x >> vet[i].y;
	}
	int vs, vc;
	cin >> vs >> vc;
	double tempo = 0;
	for (int i = 1; i < n; i++){
		double res = bs(vet[i - 1], vet[i], vs, vc, tempo);
		if (res == -1) {
			old = at;
			continue;
			tempo += 
		}
		cout << setprecision(2) << fixed << res << endl;
		return 0;
	}
	cout << "impossivel" << endl;
}