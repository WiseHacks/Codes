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

int n, q;
void solve() {
	// n ranges - (l,r,x);
	// each segment has value x;
	// q queries : ? y -> find maximum valued segment covers y
	// event - activate seg , answer q, deactivate segment;
	//first activate (1,x),answer(2,i),deactivate(3,x); order matters
	cin >> n;
	vec<pair<int, ii>> event;
	FOR(i, 0, n) {
		int l, r, x;
		cin >> l >> r >> x;
		event.pb({l, {1, x}}); //activate -1
		event.pb({r, {3, x}}); // deavctivate - 3
	}
	cin >> q;
	vi ansQ(q);
	for (int i = 0; i < q; i++) {
		int y;
		cin >> y;
		event.push_back({y, {2, i}}); // answer query store in i
	}
	sort(all(event));
	multiset<int> st;
	FOR(i, 0, event.size()) {
		if (event[i].SS.FF == 1) {
			st.insert(event[i].SS.SS);
		}
		else if (event[i].SS.FF == 2) {
			if (st.empty()) {ansQ[event[i].SS.SS] = -1; ct;}
			auto it = st.end();
			it--;
			int res = *it;
			ansQ[event[i].SS.SS] = res;
		}
		else {
			st.erase(event[i].SS.SS);
		}
	}
	vecout(ansQ, q, 0);
}

signed main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);

	testcases
	solve();
}
