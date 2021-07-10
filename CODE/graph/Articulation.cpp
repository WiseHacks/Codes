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

vi ad[100001], vs(100001), tin(100001), low(100001);
int timer = 0;
set<int> s;

void dfs(int v, int p = -1) {
	vs[v] = 1;
	low[v] = tin[v] = timer;
	timer++;
	int children = 0;
	for (auto k : ad[v]) {
		if (k == p)ct;
		if (vs[k]) {
			// backedge or k is ancestor of v;
			low[v] = min(low[v], tin[k]); // min or nearest that can be reached
		}
		else {
			dfs(k, v);
			low[v] = min(low[v], low[k]); // take min with child
			if (low[k] >= tin[v] && p != -1) {
				s.insert(v);
				// low[k]<tin[v] -> k is connected with ancestor(backedge to ancestor), =  connected with v(backedge to v)
				// in arp - >=, in bridge - >
			}
			children++;
		}
	}
	if (p == -1 && children > 1) {
		s.insert(v);
	}
}
void init(int n) {
	timer = 0;
	s.clear();
	FOR(i, 0, n + 1) {
		ad[i].clear();
		low[i] = 0;
		tin[i] = 0;
		vs[i] = 0;
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	init(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	dfs(1);
	cout << s.size() << endl;

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


