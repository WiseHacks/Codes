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
int n, m;

vec<ii> ad[100001];
vi d(100001), p(100001);
void dijkstra(int s, int t) {
	priority_queue<ii, vec<ii>, greater<ii>> q;
	q.push({0, s});
	d.assign(d.size(), INT_MAX);
	d[s] = 0;
	while (!q.empty()) {
		// lets try this one;
		int v = q.top().SS;
		int dv = q.top().FF;
		q.pop();
		if (dv != d[v])ct;
		if (v == t) {
			br;
		}
		for (auto k : ad[v]) {
			// all edge connected
			int w = k.SS;
			int u = k.FF;
			if (d[v] + w < d[u]) {
				d[u] = d[v] + w;
				p[u] = v;
				q.push({d[u], u});
			}
		}
	}
	vi path;
	while (t != s) {
		path.pb(t);
		t = p[t];
	}
	path.pb(s);
	reverse(all(path));
	vecout(path, path.size(), 0);
}
void dijkstraWithSet(int s) {
	d.assign(d.size(), INT_MAX);
	set<ii> q;
	q.insert({0, s});
	d[s] = 0;
	int t = n;
	while (!q.empty()) {
		int v = q.begin()->SS;
		int dv = q.begin()->FF;
		q.erase(q.begin()); //mark visited
		// if (v == t)br;
		for (auto k : ad[v]) {
			int u = k.FF, w = k.SS;
			if (d[v] + w < d[u]) {
				q.erase({d[u], u}); //remove
				d[u] = d[v] + w; // update
				p[u] = v;
				q.insert({d[u], u});
			}
		}
	}
	vi path;
	while (t != s) {
		path.pb(t);
		t = p[t];
	}
	path.pb(s);
	reverse(all(path));
	vecout(path, path.size(), 0);
}
void solve() {
	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		ad[u].pb({v, w});
		ad[v].pb({u, w});
	}
	dijkstra(1, n);
	dijkstraWithSet(1);

}

signed main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);

	// testcases
	solve();
}


