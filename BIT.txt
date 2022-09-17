// Binary Indexed Tree (Fenwik Tree)  
// O(log_2(n))

struct BIT
{
    int bit[N];
    int get(int x)
    {
        int s = 0;
        // // duyet nguoc cay
        // while (x <= n)
        // {
        //     s += bit[x];
        //     x += x & -x;
        // }

        while (x > 0)
        {
            s += bit[x];
            x -= x & -x;
        }
        return s;
    }

    void update(int x, int val)
    {
        // // bai toan nguoc
        // while (x > 0)
        // {
        //     bit[x] += val;
        //     x -= x & -x;
        // }

        while (x <= n)
        {
            bit[x] += val;
            x += x & -x;
        }
    }
};