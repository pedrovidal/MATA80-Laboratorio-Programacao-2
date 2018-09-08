#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main(){
	int t;
	cin >> t;
	string a, b;
	while(t--){
		cin >> a >> b;
		int ta = a.size()+1, tb = b.size()+1;
		vector<vector<int> > edist(ta, vector<int>(tb, 0));
		edist[0][0] = 0;
		for (int i = 1; i < ta; i++){
			edist[i][0] = edist[i-1][0] + 1;
		}
		for (int j = 1; j < tb; j++){
			edist[0][j] = edist[0][j-1] + 1;
		}
		for (int i = 1; i < ta; i++){
			for (int j = 1; j < tb; j++){
				if (a[i-1] == b[j-1]){
					edist[i][j] = edist[i-1][j-1];
				}
				else{
					edist[i][j] = min({edist[i-1][j-1], edist[i-1][j], edist[i][j-1]}) + 1;
				}
			}
		}
		cout << edist[ta-1][tb-1] << endl;
	}
}