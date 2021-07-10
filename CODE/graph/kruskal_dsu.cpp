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

vi parent(100001), size(100001);
// vi rank(100001);
void make_set(int v) {
	parent[v] = v;
	// rank[v]=0;
	size[v] = 1;
}
int find_set(int v) { // find leader of set, root of tree
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b) { // merge two subtrees, attach
	a = find_set(a);//leader of set which contains a;
	b = find_set(b);
	if (a != b) {
		if (size[a] < size[b]) { // a is smaller
			swap(a, b);
		}
		// if(rank[a]<rank[b])swpa(a,b);
		parent[b] = a; // b is attached to a
		size[a] += size[b]; // leader's size is updated
		// if(rank[a]==rank[b])rank[a]++;
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n + 1)make_set(i);
	using iii = tuple<int, int, int>;
	vec<iii> edges;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.pb({u, v, w});
	}
	sort(all(edges), [](iii x, iii y) {
		rt get<2>(x) < get<2>(y);
	});
	int ans = 0;
	for (auto e : edges) {
		int u, v, w;
		tie(u, v, w) = e;
		if (find_set(u) != find_set(v)) {
			// no cycle, two different tree;
			// i want to add logarithm in ans coz of minimum product thing;
			ans += log2(w);
			union_set(u, v);
		}
	}
	// ans = log(product(actual ans) 2^k);
	// ans = k;
	ans++;
	cout << ans << endl;
	/*
		To find whether u,v is in same connected comp,;
		make set for all vertices..
		then union then acc to edges, then just find the leader;
		and see if leaders r same or not		

	*/
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


