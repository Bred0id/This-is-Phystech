#include <cmath>
#include <iostream>

const long long cInf = 2e9;

long long Sqrt(long long x)
{
    long long l = 0;
    long long r = cInf;
    while (l < r)
    {
        long long mid = (l + r + 1) / 2;
        if (mid * mid <= x)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 0;
    std::cin >> t;
    while (t-- != 0)
    {
        long long k = 0;
        std::cin >> k;
        long long s = Sqrt(4 * k - 3);
        long long m = (s - 1) / 2 + 1;
        long long n = k + m;
        std::cout << n << "\n";
    }
}