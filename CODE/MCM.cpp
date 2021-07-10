int dp[1001][1001], s[1001][1001];
void print(int i, int j) {
	if (i == j)cout << "A" << i;
	else {
		cout << "(";
		print(1, s[i][j]);
		print(s[i][j] + 1, j);
		cout << ")";
	}
}
void solve() {
	int n;
	cin >> n;
	// no. of matrices;
	int m = n + 1;
	vi dimen(m);
	vecin(dimen, m, 0);
	// we have dimension;
	// we need to A1A2..An;
	// int dp[n + 1][n + 1], s[n + 1][n + 1];
	mem(dp, 0);
	mem(s, 0);
	// dp is just 'm' in standard .. which is min cost for chain
	// now computing dp[i][j] = optimal cost and for chain Ai..j;
	// s[i][j] = optimal cost split k in chain Ai..j
	// we check for all chain - all subarrays;
	// dim0,dim1 = A1's dimens | dim1,dim2 = A2's dimens
	FOR(l, 2, n + 1) { // for l, 2 to n
		// l is length;
		FOR(i, 1, n - l + 2) { // for i, 1 to n-l+1
			int j = l + i - 1; // j is last index of chain;
			// we choose k;
			dp[i][j] = INT_MAX; // take inf to find min cost;
			FOR(k, i, j) { // for k, i to j-1
				int temp  = (dp[i][k] + dp[k + 1][j] + dimen[i - 1] * dimen[k] * dimen[j]);
				if (dp[i][j] > temp) {
					dp[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
	cout << dp[1][n] << endl;
	// now we have s as  well;
	print(1, n);

}