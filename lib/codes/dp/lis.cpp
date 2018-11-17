vector<int> lis(vet.size() + 1, INF);
lis[0] = _INF;
int res = 0;
for (int i = 0; i < vet.size(); i++){
	int pos = lower_bound(lis.begin(), lis.end(), vet[i]) - lis.begin();
	lis[pos] = vet[i];
	res = max(res, pos);
}