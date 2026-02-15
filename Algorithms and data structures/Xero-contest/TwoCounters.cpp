#include <iostream>

long long Min(long long a, long long b) { return (a < b) ? a : b; }

long long BinarySearch(long long a, long long k, long long b, long long m,
                       long long x)
{
    long long l = 0;
    long long r = 2 * x + 1;
    while (l < r)
    {
        long long t = (r + l) / 2;
        long long work1 = t - t / k;
        long long work2 = t - t / m;
        long long total = 0;
        if (work1 > x / a)
        {
            total = x + 1;
        }
        else
        {
            long long sum1 = a * work1;
            if (sum1 > x)
            {
                total = x + 1;
            }
            else
            {
                if (work2 > (x - sum1) / b)
                {
                    total = x + 1;
                }
                else
                {
                    total = sum1 + b * work2;
                }
            }
        }
        if (total >= x)
        {
            r = t;
        }
        else
        {
            l = t + 1;
        }
    }
    return l;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long a = 0;
    long long k = 0;
    long long b = 0;
    long long m = 0;
    long long x = 0;
    std::cin >> a >> k >> b >> m >> x;
    std::cout << BinarySearch(a, k, b, m, x);
}
