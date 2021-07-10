string P, T;
int lp, lt;
bool check(int l, int r) {
	for (int i = 0; i < lp; i++) {
		if (T[l + i] != P[i])rt false;
	}
	rt true;

}
void solve() {

	getline(cin, T);
	getline(cin, P);
	lp = P.size(), lt = T.size();
	for (int l = 0 , r = lp - 1; r < lt; l++, r++) {
		if (check(l, r)) {
			// print index or whatever;
			cout << l << endl; //starting index
		}
	}


}

// Complexty text = n, pattern - m then no of sliding, n-m+1 so O((n-m+1)m) ~ O(nm)

