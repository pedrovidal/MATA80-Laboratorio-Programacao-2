#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main(){
	int n;
	cin >> n;
	while(n--){
		string a;
		cin >> a;
		string b = a;
		int ta = a.size() + 1;
		reverse(b.begin(), b.end());
		vector<vector<int> > lcs(ta, vector<int>(ta, 0));
		for (int i = 1; i < ta; i++){
			for (int j = 1; j < ta; j++){
				if (a[i - 1] == b[j - 1]){
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				}
				else{
					lcs[i][j] = max({lcs[i - 1][j], lcs[i][j - 1]});
				}
			}
		}
		cout << ta - lcs[ta - 1][ta - 1] - 1 << endl;
	}
}