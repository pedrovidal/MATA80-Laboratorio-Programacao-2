string res;
int i = ta - 1, j = tb - 1;
while(i + j){
	if (a[i - 1] == b[j - 1]){
		res += a[i - 1];
		i--; j--;
	}
	else if (j == 0 || (i && lcs[i - 1][j] > lcs[i][j - 1])){
		// res += a[i - 1]; // menor string q contenha a e b como subseq
		i--;
	}
	else if (j){
		// res += b[j - 1]; // menor string q contenha a e b como subseq
		j--;
	}
}
reverse(res.begin(), res.end());
cout << res << endl;