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
int maxn = 2000001;
int mod = 1000000007;
vi sieveVector(maxn, 1);
vi factVector(maxn, 1);
int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2)res = res * a, b--;
		else a = a * a, b /= 2;
	}
	rt res;
}
int powerMod(int a, int b, int m) {
	int res = 1;
	while (b) {
		if (b % 2)res = (res % m * a % m) % m, b--;
		else a = (a % m * a % m) % m, b /= 2;
	}
	rt res;
}
int modIn(int n, int m) {
	rt powerMod(n, m - 2, m);
}
void factorial() {
	for (int i = 1; i <= maxn; i++)factVector[i] = (i % mod * factVector[i - 1] % mod);
}
void sieve() {
	for (int i = 2; i * i <= maxn; i++) {
		if (sieveVector[i]) {
			for (int j = i * i; j <= maxn; j += i) {
				sieveVector[j] = 0;
			}
		}
	}
}
int ncr(int n, int r) {
	rt (factVector[n] % mod * modIn((factVector[n - r] % mod * factVector[r] % mod) % mod, mod)) % mod;
}

/*
	question : dearrange array to get the permutation which the no of
	equal position value to the original is minimum, or max no. of different value

	solution : one way is to assign value with most abundant element in each iteration,
	Best solution : Find out the maximum frequency(frequency not most frequent element) and rotate the array by that freq.,
					Thats the most optimal... (In sorted)

	Learned :
	Whenver some permutation come, think about it;

*/

void solve() {
	int n;
	cin >> n;
	vi v(n);
	vecin(v, n, 0);
	// v is sorted - this is must
	vi p;
	vi f(100001);
	FOR(i, 0, n)f[v[i]]++;
	int maxfr = *max_element(all(f));
	FOR(i, maxfr, n)p.pb(v[i]);
	FOR(i, 0, maxfr)p.pb(v[i]);
	/*
		ROF(i, n - 1, n - maxfr )p.pb(v[i]);
		FOR(i, 0, n - maxfr)p.pb(v[i]);
	*/
	vecout(p, n, 0);
	/*
		For non sorted - 
		pair elements with corresponding indices, and then sort the array -  after that 
		rotate "the indices" by maximum frequency, and then 
		so example : 1 3 2 1 3 3 ->
			pair : (1,1),(3,2),(2,3),(1,4),(3,5),(3,6) ->
			sort : (1,1)(1,4)(2,3)(3,2)(3,5)(3,6) ->
			rotate : (1,2)(1,5)(2,6)(3,1)(3,4)(3,3) 
			// assign value in the new indices : 1 in 2nd, 1 in 5th, 2 in 6th..

			We are basically using some sorted and making the indices do the rest;
			
			1 1 2 3 3 3
			1 4 3 2 5 6
			...........
			1 1 2 3 3 3
			2 5 6 1 4 3
			...........
			3 1 3 3 1 2 <- aNswer
	*/

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
