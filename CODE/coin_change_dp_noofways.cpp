
void solve() {
	// coin change;
	int n,t;
	cin>>n>>t;
	vi c(n);
	vecin(c,n,0);
	vi dp(100001);
	//dp[i] = no. of ways to achive sum i.
	dp[0]=1; // 1 way to get this
	FOR(i,1,t+1){
		for(auto x : c){
			dp[i] += dp[i-x]; //past dp
		}
	}
	/*
		FOR(i,0,t){
			for(auto x:c){
				dp[i+x] += dp[i]; //forward dp
			}
		}
	*/
}
