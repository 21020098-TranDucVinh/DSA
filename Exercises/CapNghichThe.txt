// Cho dãy số a[i] gồm n phần tử là hoán vị của các số từ 1 đến n.
// 1 cặp nghịch a_i và a_j là nghịch thế khi i < j và a_i > a_j
// Đếm số cặp nghịch thế trong mảng đã cho
// VD 3 1 2. OUTPUT = 2

#include <bits/stdc++.h>
#define N 200005
using namespace std;

int n, a[N];

struct BIT
{
    int bit[N];
    int get(int x)
    {
        int s = 0;
        // bai toan nguoc
        while (x <= n)
        {
            s += bit[x];
            x += x & -x;
        }
    }

    void update(int x, int val)
    {
        // bai toan nguoc
        while (x > 0)
        {
            bit[x] += val;
            x -= x & -x;
        }
    }
};

int main()
{
    BIT bit;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        bit.update(a[i], 1);
        ans += bit.get(a[i] + 1);
    }
    cout << ans;
    return 0;
}