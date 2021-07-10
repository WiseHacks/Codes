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

vi subSum(vi a, int A) {
	vi res;
	for (int mask = 0 ; mask < (1 << A) ; mask++) {
		int s = 0;
		for (int i = 0; i < A; i++) {
			if (mask & (1 << i))s += a[i];
		}
		res.pb(s);
	}
	sort(all(res));
	rt res;
}
void solve() {
	int n, x;
	cin >> n >> x;
	vi v(n);
	vecin(v, n, 0);
	// meet in the middle;
	vi a, b;
	FOR(i, 0, (n / 2))a.pb(v[i]);
	FOR(i, n / 2, n)b.pb(v[i]);
	int A = a.size(), B = b.size();
	vi sumA = subSum(a, A), sumB = subSum(b, B);
	int ans = 0;
	FOR(i, 0, sumA.size()) {
		ans += upper_bound(all(sumB), x - sumA[i]) - sumB.begin();
	}
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
