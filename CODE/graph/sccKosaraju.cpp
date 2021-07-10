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

vi ad[1000001], ad_tr[1000001], vs(1000001), order, component;
vi root(1000001);// root[i] = root of i in scc containing i;
vi root_fun(1000001); // root_fun[i] = fun value of scc with root 'i'
vi ad_scc[1000001];
void dfs(int v) {
	vs[v] = 1;
	for (auto k : ad[v]) {
		if (!vs[k])dfs(k);
	}
	order.pb(v); // veritces in increasing order of their outTime
}
void dfs2(int v) {
	vs[v] = 1;
	component.pb(v);
	for (auto k : ad_tr[v]) {
		if (!vs[k]) {
			dfs2(k);
		}
	}
}
void solve() {
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	vi F(n + 1);
	vecin(F, n + 1, 1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		ad[u].pb(v);
		ad_tr[v].pb(u);
	}
	dfs(s); //now we have order;
	reverse(all(order));// topological order, indeg is 0;
	vs.assign(n + 1, 0);
	int cntScc = 0;
	for (auto v : order) {
		if (vs[v])ct;
		dfs2(v);
		cntScc++;
		vecout(component, component.size(), 0);
		int root_scc = component[0]; // root we have,;
		int Total_fun = 0;
		for (auto k : component) {
			// we assign them a root, and we have scc fun value assigned with root in root_fun;
			root[k] = root_scc;
			Total_fun += F[k];
		}
		root_fun[root_scc] = Total_fun;
		component.clear();
	}
	// lets make a condensation graph;
	FOR(v, 1, n + 1) {
		for (auto k : ad[v]) {
			int root_v = root[v], root_k = root[k];
			if (root_v != root_k) {
				// there is a edge v-k between this two scc;
				ad_scc[root_v].pb(root_k);
			}
		}
	}
	s = root[s], e = root[e];
	// we have scc graph, and we have source and destination..
	// max path from s to e;
	if (s == e) {
		cout << root_fun[s] << endl;
		rt;
	}
	cout << "No of SCC - " << cntScc << endl;

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


