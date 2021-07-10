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


int fun(int n,int wt){
	rt max(fun(n,wt+v[n-1]),fun(n-1,wt));
}
void solve() {
	//
	// knapsack
	int n=5;
	vi p(n);
	vin(p,n,0);
	vi w(n);
	vecin(w,n,0);
	// choices, we take, not take - le na le, 
	//           / \ 
	//          take 1 occurence, 2 occurence, 3 occurence <-iterative
	//
	// int dp[W+1];
 //    memset(dp, 0, sizeof dp);
 
 //    // Fill dp[] using above recursive formula
 //    for (int i=0; i<=W; i++)
 //      for (int j=0; j<n; j++)
 //         if (wt[j] <= i)
 //            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
 
 //    return dp[W];

	// unbounded ka code, bounded to pata hi hai
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
