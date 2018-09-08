#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
// #define INF INT_MAX

signed main(){
	string a, b;
	while(cin >> a >> b, a != "*" && b != "*"){
		int ta = a.size(), tb = b.size();
		a = "$" + a;
		b = "$" + b;
		vector<int> da(26, 0);
		int INF = ta + tb;
		vector<vector<int> > edist(ta+1, vector<int>(tb+1, INF));
		for (int i = 0; i <= ta; i++){
			edist[i][0] = i;
		}
		for (int j = 0; j <= tb; j++){
			edist[0][j] = j;
		}
		for (int i = 1; i <= ta; i++){
			int db = 0;
			for (int j = 1; j <= tb; j++){
				int k = da[b[j] - 'a'], l = db;
				int cost = 1;
				if (a[i] == b[j]){
					cost = 0;
					db = j;
				}
				// cout << k << " " << l << endl;
				int val;
				if (l <= 0 || k <= 0){
					val = ta + tb + (i - k - 1) + 1 + (j - l - 1);
				}
				else{
					val = edist[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1);
				}
				edist[i][j] = min({	edist[i - 1][j - 1] + cost,
									edist[i][j - 1] + 1,
									edist[i - 1][j] + 1,
									val});
				// cout << edist[i][j] << " ";
			}
			da[a[i] - 'a'] = i;
			// cout << endl;
		}
		cout << edist[ta][tb] << endl;
	}
}