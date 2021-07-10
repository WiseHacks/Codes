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
int maxn = 2000001;
int mod = 1000000007;
vi sieveVector(maxn, 1);
vi factVector(maxn, 1);
int power(int v, int b) {
	int res = 1;
	while (b) {
		if (b % 2)res = res * v, b--;
		else v = v * v, b /= 2;
	}
	rt res;
}
int powerMod(int v, int b, int m) {
	int res = 1;
	while (b) {
		if (b % 2)res = (res % m * v % m) % m, b--;
		else v = (v % m * v % m) % m, b /= 2;
	}
	rt res;
}
int modIn(int n, int m) {
	rt powerMod(n, m - 2, m);
}
void factorial() {
	for (int i = 1; i <= maxn; i++)factVector[i] = (i % mod * factVector[i - 1] % mod);
}
void sieve() {
	for (int i = 2; i * i <= maxn; i++) {
		if (sieveVector[i]) {
			for (int j = i * i; j <= maxn; j += i) {
				sieveVector[j] = 0;
			}
		}
	}
}

int ncr(int n, int r) {
	rt (factVector[n] % mod * modIn((factVector[n - r] % mod * factVector[r] % mod) % mod, mod)) % mod;
}


vi ad[100001];
vec<ii> r(100001);
int dp[100001][2];
int dfs(int v, int c, int  p) {
	if (dp[v][c] != -1)rt dp[v][c];
	int res = 0;
	for (auto k : ad[v]) {
		if (k == p)ct;
		int temp = 0;
		if (c == 0) {
			temp =  max(abs(r[k].FF - r[v].FF) + dfs(k, 0, v), abs(r[k].SS - r[v].FF) + dfs(k, 1, v));
		}
		else {
			temp = max(abs(r[k].FF - r[v].SS) + dfs(k, 0, v), abs(r[k].SS - r[v].SS) + dfs(k, 1, v));
		}
		res += temp;
	}
	rt dp[v][c] = res;
}
void solve() {
	int n;
	cin >> n;
	FOR(i, 0, n + 1)ad[i].clear();
	mem(dp, -1);
	FOR(i, 1, n + 1) {
		cin >> r[i].FF >> r[i].SS;
	}
	vec<ii> e;
	int m = n - 1;
	while (m--) {
		int u, v;
		cin >> u >> v;
		e.pb({u, v});
		ad[u].pb(v);
		ad[v].pb(u);
	}
	int ans = max(dfs(1, 0, -1), dfs(1, 1, -1));
	cout << ans << endl;

}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);

	testcases
	solve();
}
