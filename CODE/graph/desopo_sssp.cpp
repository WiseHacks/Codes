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

int INF = 1000000000;
int n, m;
vec<ii> ad[100001];
vi d(100001), p(100001);
void desopo(int s) {
	d.assign(d.size(), INF);
	d[s] = 0;
	vi m(n, 2);
	// m0 = already processed in past, m1 = currently , m2 = yet to be
	deque<int> q;
	q.push_front(s);
	p[s] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		// move it to m0;
		m[v] = 0; // processed
		for (auto k : ad[v]) {
			int u = k.FF, w = k.SS;
			if (d[v] + w < d[u]) {
				// improvise;
				d[u] = d[v] + w;
				p[u] = v;
				if (m[u] == 0) {
					// if already processed;
					// now it is currently calc;
					m[u] = 1;
					q.push_front(u);
				}
				else if (m[u] == 2) {
					m[u] = 1;
					q.push_back(u);
				}
			}
		}
	}
	vi path;
	int t = n;
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
	desopo(1);
	// vecout(d, n + 1, 1);
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


