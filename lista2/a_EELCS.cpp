#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main(){
	string a, b;
	cin >> a >> b;
	int ta = a.size()+1, tb = b.size()+1;
	vector<vector<int> > lcs(ta, vector<int>(tb, 0));
	for (int i = 1; i < ta; i++){
		for (int j = 1; j < tb; j++){
			if (a[i-1] == b[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	cout << lcs[ta-1][tb-1] << endl;
}