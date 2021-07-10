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

vector<int> placed;
int ans = 0 , n;
void fun(int row) {
	if (row == n) {ans++; rt;}
	for (int col = 0; col < n; col++) {
		bool safe = 1;
		for (int prow = 0; prow < row; prow++) {
			int pcol = placed[prow];
			if (pcol == col || (abs(row - prow) == abs(col - pcol))) {
				safe = 0;
			}
		}
		if (safe) {
			placed.push_back(col);
			fun(row + 1);
			placed.pop_back();
		}
	}

}
void solve() {
	// int n;
	cin >> n;
	fun(0);
	cout << ans << endl;

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
