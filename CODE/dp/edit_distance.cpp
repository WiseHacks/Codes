int dp[500][500];
int fun(string &A, string &B, int m, int n){
    if(dp[m][n]!=-1)return dp[m][n];
    if(m==0)return dp[m][n]=n;
    if(n==0)return dp[m][n]=m;
    if(A[m-1] == B[n-1])return dp[m][n]=fun(A,B,m-1,n-1);
    return dp[m][n]=1 + min(fun(A,B,m,n-1), min(fun(A,B,m-1,n), fun(A,B,m-1,n-1)));
}
int Solution::minDistance(string A, string B) {
    memset(dp,-1,sizeof(dp));
    return fun(A,B,A.size(),B.size());
    
    // easy three choices, if m==0 then n insert, if n==0 then m delete;
    // if last equal, no operation, else three choice, insert -> m,n-1
    // delete m-1,n 
    // replace m-1,n-1
}

