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

void lis(vector<int> v) {
	vi sols; // value.. sols - > LIS
	vi pos(v.size());
	FOR(i, 0, v.size()) {
		int k = v[i];
		if (sols.empty() || k > sols.back()) {
			sols.pb(k);
			pos[i] = sols.size();
		}
		else {
			auto it = lower_bound(all(sols), k);
			// what we do..
			// found lower bound x <=k
			*it = k;
			// lowerbd - begin is length of lis.. so we find that and update to smallest value which is k
			// we update

			pos[i] = it - sols.begin() + 1;

		}
		// vecout(sols, sols.size(), 0);
		// NOTE - sols is not the lis but sols.sz() is max lis length
		//
	}
	cout << "sols :";
	vecout(sols, sols.size(), 0);
	vi seq;
	cout << "Pos :";
	vecout(pos, pos.size(), 0);
	int pt = sols.size();
	ROF(i, pos.size() - 1, 0) {
		if (pos[i] == pt) {
			seq.pb(v[i]);
			pt--;
		}
	}
	reverse(all(seq));
	cout << "sequence :";
	vecout(seq, seq.size(), 0);
	
	// for no dec... change k>=sols.back() and lowerbound to upperbound	
}

void solve() {
	// LIS problem;
	// ending at i (length, ending) | if v[i]>end -> (len+1, v[i]) else, lowerbound change value to smallest ones
	// vi v = {2, 1, 4, 5, 2, 3, 6, 8};
	/*
	2 = pb 2 , length = 1
	1 = less than, replace 2 with smallest.. 1
	1 4  = pb 4
	1 4 5 = 5>4 so pb 5
	1 2 5 = update the value
	1 2 3 = update the value
	1 2 3 6 = ans so on..
	1 2 3 6 8
	1 2 3 6 8
	*/
	vi v = {1, 4, 5, 6, 4, 9, 2, 5, 6, 7};
	lis(v);
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
