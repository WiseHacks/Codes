/*
	Relation
	rn = max(pi,rn-i); i = 1 to n (inclusive);
*/
int dp[10001] = {0};
vi p(10001);
int fun(vi price, int n) {
	if (n == 0)rt 0;
	int res = -1;
	/*
		s = 0;
		q = 0;
	*/
	for (int i = 1; i <= n; i++) {
		/*
			if(q < price[i-1] + fun(price,n-i)){
				// update q, 
				// update s;
				// update global p[n] = i;
			}
		*/
		res = max(res, price[i - 1] + fun(price, n - i));
	}
	rt res;
}
void solve() {
	int n;
	cin >> n;
	vi price(n);
	vecin(price, n, 0);
	cout << fun(price, n) << endl;
	mem(dp, 0);
	//
	FOR(i, 1, n + 1) {
		FOR(j, 1, i + 1) {
			dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
			// same relation, length is 'i' and cutting in 1 to.. i
		}
	}
	cout << dp[n] << endl;

	/*
	This is for printing cut lengths..
	// si is the length we cut and take it apart from a rod with length i 
	vi s(10001); // optimal size to cut off
	mem(dp, 0);
	FOR(i, 1, n + 1) {
		FOR(j, 1, i + 1) {
			if (dp[i] < price[j - 1] + dp[i - j]) {
				dp[i] = price[j - 1] + dp[i - j];
				s[i] = j;
			}
		}
	}
	// s is size that we cut
	vecout(s, n + 1, 1);
	while (n > 0) {
		cout << s[n] << " ";
		n -= s[n];
		// we cut in s[n] and n-s[n]... n is one part... now we 
		// cut from n - s[n] part -  thats why n is n -= s[n]..
		// this way we can get length 
	}
	*/
}

