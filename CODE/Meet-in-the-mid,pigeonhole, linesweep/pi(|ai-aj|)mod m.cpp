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
	int n,m;
	cin>>n>>m;
	vi v(n);
	vecin(v,n,0);
	// pi(|ai-aj|) % m 
	// n<10^5 , m<10^3 => modulo is small
	// ans is between 0 to m-1
	if(n>m)cout<<"0\n";
	// becoz ans is straight away 0 if ai%m == aj%m;
	// if n>m we are bound to get any two equals;
	else{
		// two loops
	}


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
