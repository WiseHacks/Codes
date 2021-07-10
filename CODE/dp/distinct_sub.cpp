int dp[1000][1000];
int fun(string &A,string &B,int n,int m){
    if(dp[n][m]!=-1)return dp[n][m];
    if(n==0){
        if(m==0)return dp[n][m]=1;
        else return dp[n][m]=0;
    }
    if(m==0)return dp[n][m]=1;
    if(A[n-1]==B[m-1]){
        // we have choice; take it or not take it;
        return dp[n][m]=fun(A,B,n-1,m-1)+fun(A,B,n-1,m);
    }
    else return dp[n][m]=fun(A,B,n-1,m);
}
int Solution::numDistinct(string A, string B) {
    // rabbbit, rabbit => lcs = b.sz | 
    // we only have length 
    // dp[i][j] = ..i ..j
    memset(dp,-1,sizeof(dp));
    return fun(A,B,A.size(),B.size());
}

