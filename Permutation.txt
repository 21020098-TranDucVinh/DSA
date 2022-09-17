//
void Swap(int &a,int &b)
{
    int t = a;
    a = b;
    b = t;
}

void Next(int a[], int n)
{
    int i, j;
    for(i = n - 1; i > 0; i--)
        if(a[i] > a[i-1]) break;
    if(i == 0) {
        return;
    }

    for(j = n - 1; a[j] <= a[i-1]; j--);
        Swap(a[i-1], a[j]);
    for(j = n - 1; i < j; i++, j--)
        Swap(a[i], a[j]);
}

// C2
next_permutation(a.begin(), a.end()) // <algorithm>