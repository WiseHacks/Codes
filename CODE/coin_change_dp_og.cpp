void solve() {
	// coin change;
	int n,t;
	cin>>n>>t;
	vi c(n);
	vecin(c,n,0);
	vi dp(100001);
	//dp[i] = no. of ways to achive sum i.
	dp[0]=0; // 0 coins used to get 0
	FOR(i,1,t+1){
		for(auto x : c){
			dp[i] = min(1+dp[i-x],dp[i]); //past dp
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
