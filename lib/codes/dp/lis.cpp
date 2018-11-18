vi lis(v.size() + 1, INF);
lis[0] = _INF;
int res = 0;
for (int i = 0; i < v.size(); i++){
	int pos = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
	lis[pos] = v[i];
	res = max(res, pos);
}