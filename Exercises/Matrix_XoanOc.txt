std::vector<std::vector<int>> spiralNumbers(int n)
{
    std::vector<std::vector<int>> a;
    std::vector<int> b;
    for (int i=0; i<n; i++) b.push_back(1);
    for (int i=0; i<n; i++) a.push_back(b);
    int l=0;
    int r = n-1;
    int k=0;
    while (k<n*n){
        if (k<n*n){
            for (int j=l; j<=r; j++){
                k++;
                a[l][j] = k;
            }
        }
        if (k<n*n){
            for (int i=l+1; i<=r; i++){
                k++;
                a[i][r] = k;
            }
        }
        if (k<n*n){
            for (int j=r-1; j>=l; j--){
                k++;
                a[r][j] = k;
            }
        }
        if (k<n*n){
            for (int i=r-1; i>=l+1; i--){
                k++;
                a[i][l] = k;
            }
        }
        l++; r--;
    }
    return a;
}