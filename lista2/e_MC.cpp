#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main(){
	int t = 1;
	string a, b;
	while(cin >> a, a != "#"){
		cin >> b;
		int ta = a.size()+1, tb = b.size()+1;
		vector<vector<int> > lcs(ta, vector<int>(tb, 0));
		for (int i = 0; i < ta; i++){
			for (int j = 0; j < tb; j++){
				if (i == 0 || j == 0){
					lcs[i][j] = 0;
					continue;
				}
				else if (a[i-1] == b[j-1]){
					lcs[i][j] = lcs[i-1][j-1] + 1;
				}
				else {
					lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
				}
				// cout << lcs[i][j] << " ";
			}
			// cout << endl;
		}
		// cout << endl;
		int res = 0;
		int i = ta - 1, j = tb - 1;
		while(i + j != 0){
			if (a[i - 1] == b [j - 1]){
				i--;
				j--;
			}
			else{
				if (i && j && lcs[i - 1][j] > lcs[i][j - 1]){
					res += 15;
					i--;
				}
				else if (j){
					res += 30;
					j--;
				}
				else if (i){
					res += 15;
					i--;
				}
			}
		}
		cout << res << endl;
	}
}