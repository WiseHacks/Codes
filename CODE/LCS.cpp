
/*
    relation - if(xm-1 == yn-1)rt fun(m-1,n-1)+1, else rt max(f(m-1,n) , f(m,n-1));

*/

int dp[1001][1001], indicator[1001][1001];
void print(int i, int j, string x) {
    if (i == 0 || j == 0)rt ;
    if (indicator[i][j] == 0) {
        print(i - 1, j - 1, x);
        cout << x[i - 1];
    }
    else if (indicator[i][j] == -1) {
        print(i - 1, j, x);
    }
    else print(i, j - 1, x);
}
void solve() {
    string x, y;
    cin >> x >> y;
    int m = x.length(), n = y.length();
    // int dp[m + 1][n + 1], indicator[m + 1][n + 1];
    // dp[i][j] = max length of lcs of (x1..i , y1..j);
    // at some prefix.. if its equal then + 1 and add dp[i-1][j-1].. if its not then you got something else;
    mem(dp, 0);
    FOR(i, 1, m + 1) {
        FOR(j, 1, n + 1) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                indicator[i][j] = 0;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                indicator[i][j] = -1;
            }
            else {
                dp[i][j] = dp[i][j - 1];
                indicator[i][j] = 1;
            }
        }
    }
    cout << dp[m][n] << endl;
    print(m, n, x);

}