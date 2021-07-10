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

vi ad[100001], tin(100001), tout(100001);
// given graph is tree
vec<vi> up(100001, vi (20));
int n, m, l, N;
int timer = 0;
void dfs(int v, int p) {
    up[v][0] = p; // one ancestor above it;
    tin[v] = timer++;
    FOR(i, 1, l + 1) {
        up[v][i] = up[up[v][i - 1]][i - 1]; // mid's 2^i/2 = 2^i-1
    }
    for (auto k : ad[v]) {
        if (k != p) {
            dfs(k, v); // this only work in case of tree otherwise we need vs
        }
    }
    tout[v] = timer++;
}
bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
int lca(int u, int v) {
    if (is_ancestor(u, v))rt u;
    if (is_ancestor(v, u))rt v;
    ROF(i, l, 0) {
        if (!is_ancestor(up[u][i], v)) {
            // this is to move u as up as possible s.t it is not ancestor of a.
            // cout << up[u][i] << endl;
            u = up[u][i];
        }
    }
    // any more than that will lead to ancestor with a, so one above current u is actually LCA
    return up[u][0];
}
void preprocess(int root) {
    timer = 0;
    l = 0 , N = n;
    while (N)l++, N /= 2;
    FOR(i, 0, n + 1) {
        tin[i] = 0;
        tout[i] = 0;
        up[i].assign(up[i].size(), -1);
    }
    dfs(root, root);
}
void solve() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        ad[u].pb(v);
        ad[v].pb(u);
    }
    preprocess(1);
    // now this is easy lol
    // cout << lca(12, 9) << endl;

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


