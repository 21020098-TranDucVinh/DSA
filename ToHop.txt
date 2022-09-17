//C1 (DP)
int C(int k, int n)
{
    int a[100][100];
    if (k==0||k==n) return 1;
    else for (int i=0;i<=k;i++)
        for (int j=i;j<=n;j++)
            if (i==0||i==j) a[i][j]=1;
            else a[i][j]=a[i][j-1]+a[i-1][j-1];
    return a[k][n];
}

//C2
int C(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    return C(k - 1, n - 1) + C(k, n - 1);
}

// C3
long long gt(int n) {
    long long s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return s;
}
long long C(int k, int n) {
    return  gt(n) / (gt(k)*gt(n - k));
}

// C4
long long numberOfCombinations( int n, int k )
{
    double res = 1;
    for ( int i = 1; i <= k ; i ++ , n-- )
    {
        res = res *n/i;
    }
    return (long long)res;
}