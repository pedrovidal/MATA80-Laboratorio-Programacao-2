#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pdd pair<double, double>
#define endl '\n'
#define x first
#define y second
#define EPS 1e-2

double dist(pdd old, pdd at){
	return sqrt( (old.x - at.x) * (old.x - at.x) + (old.y - at.y) * (old.y - at.y));
}

signed main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pdd> vet(n);
	pdd jureg;
	cin >> jureg.x >> jureg.y;
	for (int i = 0; i < n; i++){
		cin >> vet[i].x >> vet[i].y;
		if (i == 0 && vet[i] == jureg){
			cout << "0.00" << endl;
			return 0;
		}
	}
	double vs, vc;
	cin >> vs >> vc;
	vector<double> tempo;
	tempo.push_back(0);
	for (int i = 1; i < n; i++){
		tempo.push_back(tempo[i - 1] + dist(vet[i], vet[i-1]) / vc);
	}
	double ini = 0, fim = tempo[n-1], tc, ts;
	while(abs(ini - fim) > 1e-8){
		tc = (ini + fim) / 2;
		int pos = upper_bound(tempo.begin(), tempo.end(), tc) - tempo.begin();
		pos--;
		double t = tc - tempo[pos], T = tempo[pos + 1] - tempo[pos];
		pdd lugar;
		if (abs(tempo[pos] - tc) <= 1e-2 || pos == n - 1){
			lugar = vet[pos];
		}
		else{
			lugar = make_pair(vet[pos].x + (vet[pos + 1].x - vet[pos].x) * t / T, vet[pos].y + (vet[pos + 1].y - vet[pos].y) * t / T);
		}
		ts = dist(jureg, lugar) / vs;
		// cout << ts << " " << tc << " " << (abs(ts - tc) <= 1e-2) << endl;
		if (ts <= tc){
			fim = tc;
		}
		else{
			ini = tc;
		}
	}
	if ((abs(ts - tc) <= 1e-2)){
		cout << setprecision(2) << fixed << ts << endl;
	}
	else cout << "impossivel" << endl;	
}