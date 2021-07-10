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
	int n, k;
	cin >> n >> k;
	vi A(n + 1);
	vecin(A, n + 1, 1);
	int dp[k + 1];
	FOR(i, 0, k + 1)dp[i] = 1;
	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		int move = 0;
		for (int j = 1; j <= n; j++) {
			if (i >= A[j]) {
				move = 1;
				dp[i] = dp[i] * dp[i - A[j]];
			}
		}
		dp[i] = 1 - dp[i];
		if (move == 0)dp[i] = 0;
	}
	if (dp[k]) {
		cout << "First\n";
	}
	else cout << "Second\n";
}

signed main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);

	// testcases
	solve();
}
