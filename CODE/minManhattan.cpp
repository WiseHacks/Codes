
void solve() {
	int n;
	cin >> n;
	vi v(n);
	vecin(v, n, 0);
	sort(all(v));
	ll sum = 0;
	FOR(i, 0, n)sum += abs(v[i] - v[ceil((double)n / 2) - 1]);
	cout << sum << endl;
}
