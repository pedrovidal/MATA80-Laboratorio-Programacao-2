vvi edist(ta, vi(tb, 0));
for (int i = 0; i < ta; i++){
	for (int j = 0; j < tb; j++){
		if (i == 0 || j == 0){ edist[i][j] = max(i, j); continue;}
		edist[i][j] = (a[i-1] == b[j-1] ? edist[i-1][j-1] : min({edist[i-1][j-1], edist[i-1][j], edist[i][j-1]}) + 1);
	}
}
cout << edist[ta-1][tb-1] << endl;
