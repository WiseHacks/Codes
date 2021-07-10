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

int fun(int n, int i) {
	if (n < i)rt 0;
	if (i == n)rt 1;
	rt fun(n, i + 1) + fun(n - i, i); // this is becoz of sorted thing
}
void solve() {
	int n;
	cin >> n;
	/*
		N as sum of natural numbers :
		N = 4 : 1 1 1 1 ,1 1 2, 1 3, 2 2, 4 
	*/
	
	// dp[i][taken] = we r left with i (i is sum~n), and taken is last element we took;
	// dp[i][taken] = dp[i][j] = sigma(j=taken,i) dp[i-j][j];
	// dp[i][taken] = dp[i-taken][taken](2 choice, taken so i-taken, and taken)
	//   + dp[i][taken+1](moved up with same i and new choice);
	// either we take taken  or we move up
	//------------------------------------------------------------------------------------------------------------

	int dp[n + 4][n + 4];
	mem(dp, 0);
	for (int i = 1; i <= n; i++)dp[i][i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			dp[i][j] = dp[i - j][j] + dp[i][j + 1];
		}
	}
	cout << fun(n, 1) << " " << dp[n][1] << endl;

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
