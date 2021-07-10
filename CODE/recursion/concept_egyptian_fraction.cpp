#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(I,v,b) for(int I=v;I<b;I++)
#define FORit(it,v) for(auto it=v.begin();it!=v.end();it++)
#define ROF(I,v,b) for(int I=v;I>=b;I--)
#define vec vector
#define vi vec<int>
#define pb push_back
#define pp pop_back
#define all(x) x.begin(),x.end()
#define testcases int tc;cin>>tc;while(tc--)
#define mem(v,k) memset(v,k,sizeof(v))
#define FF first
#define SS second
#define rt return
#define br break
#define ct continue
#define ii pair<int,int>
#define vecin(v,n,index) for(int I=index;I<n;I++)cin>>v[I];
#define vecout(v,n,index) for(int I=index;I<n;I++)cout<<v[I]<<" ";cout<<endl;

set<vi> sol;
void fun(int nm, int dr, int n, vi s) {
	if (nm == 0 || dr == 0)rt;
	if (n == 1) {
		if (nm != 1)rt;
		s.pb(dr);
		// vecout(s, s.size(), 0);
		if (s[0] > 0)sol.insert(s);
		// s.pp();
	}
	vi range;
	int k = n * dr / nm;
	// cout << "k = " << k << endl;
	// minimum| 1/k < nm/dr | maximum possible p from p,q,r,s should be less than nm/dr
	while (k * nm > (dr)) {
		range.pb(k--);
	}
	for (auto r : range) {
		int x = 1, y = r;
		s.pb(r);
		int g = __gcd(nm * r - dr, dr * r);
		int p = (nm * r - dr) / g, q = (dr * r) / g;
		// cout << p << " " << q << " " << r << " " << n << endl;
		fun(p, q, n - 1, s);
		s.pp();
	}
	rt;
}
void solve() {
	int n;
	cin >> n;
	int ans = -1;
	for (auto k : sol) {
		int a, b, c, d;
		if (n % k[0] == 0)a = n / k[0];
		if (n % k[1] == 0)b = n / k[1];
		if (n % k[2] == 0)c = n / k[2];
		if (n % k[3] == 0)d = n / k[3];
		if (a + b + c + d == n) {
			ans = max(ans, a * b * c * d);
		}
	}
	cout << ans << endl;

}

signed main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);

	vi s;
	fun(1, 1, 4, s);
	testcases
	solve();
}
