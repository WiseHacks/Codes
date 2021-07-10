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

void solve() {
	int n, x;
	cin >> n >> x;
	vi v(n);
	vecin(v, n, 0);
	sort(all(v));
	// iterate over values of j and check for ai,ak;
	int ans = INT_MAX;
	FOR(j, 1, n - 1) {
		int i = 0, k = n - 1;
		while (i < j && k > j) {
			int sum = v[i] + v[j] + v[k];
			ans = min(ans, abs(x - sum));
			if (sum > x)k--;
			else i++;
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

	testcases
	solve();
}
