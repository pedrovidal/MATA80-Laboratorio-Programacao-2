vvi lcs(ta, vi(tb, 0));
for (int i = 1; i < ta; i++){
	for (int j = 1; j < tb; j++){
		lcs[i][j] = (a[i - 1] == b[j - 1] ? lcs[i - 1][j - 1] + 1 : max(lcs[i-1][j], lcs[i][j-1]));
	}
}
cout << lcs[ta-1][tb-1] << endl;