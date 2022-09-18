// Số Catalan thứ n = 2nCn - 2nC(n + 1) = 2nCn * 1 / (n + 1)
// Ứng dụng parenthesis
// Polygon triangulation
// Handshake across a table 
// Binary tree

long long M = 1000000000 + 7;
 
long long catalanDP(long long n) 
{ 
    long long catalan[n+1]; 
    catalan[0] = catalan[1] = 1; 
    for (int i=2; i<=n; i++) 
    { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++)
        { 
            catalan[i] += catalan[j] * catalan[i-j-1]; 
                catalan[i] %= M; 
        }
    } 
    return catalan[n]; 
}