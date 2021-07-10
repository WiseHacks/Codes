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

vi A(1000), B(1000);
int n;
int fun(int i, int j) {
	// (a1...ai)(b1...bj)
	if (i == 0 || j == 0)rt 0;
	if (A[i] == B[i])rt 1 + fun(i - 1, j - 1);
	rt max(fun(i - 1, j), fun(i, j - 1));
}
void solve() {
	// LCS;
	// int n;
	cin >> n;
	// vi A(n), B(n);
	vecin(A, n, 0);
	vecin(B, n, 0);

	// dp[i][j] = (a1...ai)(b1...bj);


	int dp[1000][1000];
	mem(dp, 0);
	FOR(i, 1, n + 1) {
		FOR(j, 1, n + 1) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (dp[i - 1][j] >= dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}
	cout << fun(n, n) << endl;
	// 
	/*
		Trick : 
		
		
	*/
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
