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

vi q;
int fun(int i, int j) {
	// maximum difference a player can create
	if (i > j)rt 0;
	rt max(q[i] - fun(i + 1, j), q[j] - fun(i, j - 1));
}

void solve() {
	// deque<int> q;
	// 2 players, gain points from front,back acc to their turn..
	//sa-sb= diff.. both player wants to increase difference..
	//  scur-snext  -> dif max jo bhi player ho.. fark ni padta,
	// agr pdta bhi to recursion order se set hai..
	// jaise 'a' first then we need dif sa-fn() max...
	// then fn called .. now we need diff max agai so ..
	// BOTH players play optimally.. both wants to increase their score
	// so difference max..
	int n = 4;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		q.push_back(k);
	}
	cout << fun(0, 3) << endl;
	// tc = {3,1,10,4} ans = 8

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
