int ucln(int a, int b)
{
    while (b!=0)
    {
        int x = a%b;
        a = b;
        b = x;
    }
    return a;
}