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

void solve() {
	// linesweep;
	// n - segments | (li,ri);
	// k is given;
	// goooood
	int n;
	cin >> n;
	vec<ii> events;
	FOR(i, 0, n) {
		int l, r;
		cin >> l >> r;
		events.pb({l, +1});
		events.pb({r, -1});
	}
	/*
		map<int,int> mp;
		mp[l]++;
		mp[r]--;
		to have them combined ; see input (0,1)(1,2);
	*/
	sort(all(events));
	int cnt = 0;
	int lenCovered[n + 1];
	mem(lenCovered, 0);
	FOR(i, 0, events.size()) {
		int j = i;
		while (j < events.size() && (events[j].FF == events[i].FF)) {
			cnt += events[j].FF;
			j++;
		}
		// the while loop is basically adding for same point,
		// processing all same pts together and jumping to next pt
		i = j - 1;
		if (i != events.size() - 1) {
			int segLen = events[i + 1].FF - events[i].FF;
			lenCovered[cnt] += segLen;
		}
	}
	// (0,1) (1,-1) (1,1) (2,-1) - events array
	ROF(i, n - 1, 1)lenCovered[i] += lenCovered[i + 1];


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
