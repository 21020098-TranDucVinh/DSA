// (A * B) mod M by Indian Multiplication.
int multiply_modulo(int A, int B, int M) 
{
    if (B == 0)
        return 0;
 
    long long T = multiply_modulo(A, B / 2, M) % M;
 
    if (B & 1)
        return ((T + T) % M + A % M) % M;
    else
        return (T + T) % M;
}