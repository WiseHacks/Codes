
/*
    dp[i] = length longest lis so far upto i..
    dp[i] = dp[j]+1 if(vi>vj) for all j<i
*/


void solve() {

/*





WRONG CODE LOLLLL










*/
    int n;
    cin >> n;
    vi v(n + 1);
    vecin(v, n + 1, 1);
    int dp[n + 1];
    FOR(i, 1, n + 1)dp[i] = 1;
    // dp[i] = max length of lis upto v1..i;
    int p[n + 1];
    mem(p, -1);
    FOR(i, 1, n + 1) {
        FOR(j, 1, i) {
            if (v[i] > v[j]) {
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
            else dp[i] = dp[j];
        }
    }
    // we have the length;
    cout << dp[n] << endl;
    vecout(dp, n + 1, 1);
    vecout(p, n + 1, 1);
    cout << "Subsequence -- > \n";
    int i = n;
    vi ans;
    while (1) {
        ans.pb(v[i]);
        i = p[i];
        if (i == -1)br;
    }
    reverse(all(ans));
    vecout(ans, ans.size(), 0);

}
