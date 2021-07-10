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
	question : N value, a1,a2,a3... find first value x>=1 which can not be created by any subset sum;
	// curcheck : checking if its possible to generate that sum, 
	if sum<curcheck; ans curcheck
	else curcheck=sum+1;, everything upto sum can be created;
*/
void solve() {
	int n;
	cin >> n;
	vi v(n);
	vecin(v, n, 0);
	sort(all(v));
	int sum = 0, i = 0, curcheck = 1;
	while (1) {
		while (v[i] <= curcheck && i < n) {
			sum += v[i];
			i++;
		}
		if (sum < curcheck) {
			cout << curcheck << endl;
			rt;
		}
		else {
			curcheck = sum + 1;
		}
	}
	/*
		1 1 2 - 5 = 1 +1+2+1
		1 3 4 - 2 = 1+1
		1 2 5 6 - 4 = 1+2+1

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
