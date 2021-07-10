int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int res = INT_MIN, temp = 0;
    for(int i = 0;i<n;i++){
        temp = temp + A[i];
        if(temp>res){
            res = temp;
        }
        if(temp<0)temp = 0;
    }
    return res;
    // DP approach
    vi dp(n);
	dp[0] = v[0];
	for (int i = 1; i < n; i++) {
		dp[i] = v[i] + max(0,dp[i-1]);
		// int s = dp[i - 1] + v[i];
		// if (s < 0)dp[i] = max(dp[i], v[i]);
		// else dp[i] = max(dp[i], v[i] + dp[i - 1]);
	}
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

