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
#define endl "\n"
#define ii pair<int,int>
#define vecin(v,n,index) for(int I=index;I<n;I++)cin>>v[I];
#define vecout(v,n,index) for(int I=index;I<n;I++)cout<<v[I]<<" ";cout<<endl;

void kahn(int n) {
	queue<int> q;
	vi res;
	FOR(i, 1, n + 1) {
		if (Inedge[i] == 0)q.push(i);
	}
	while (!q.empty()) {
		int v = q.front();
		res.pb(v);
		q.pop();
		for (auto k : ad[v]) {
			Inedge[k]--;
			if (Inedge[k] == 0)q.push(k);
		}
	}
}
void solve() {
	;
}

signed main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);

	testcases
	solve();
}


