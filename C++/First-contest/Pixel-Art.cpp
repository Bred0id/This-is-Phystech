#include <iostream>
#include <cstdint>

int64_t Min(int64_t a, int64_t b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}

int64_t Max(int64_t a, int64_t b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int main()
{
    int64_t n = 0;
    int64_t m = 0;
    int64_t k = 0;
    std::cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        std::cout << n * (m / k) + (n / k) * (m % k) + Max(0, Min(n % k - 1, i) - Max(0, i - m % k + 1) + 1) +
                         Max(0, Min(n % k - 1, i + k) - Max(0, i - m % k + 1 + k) + 1)
                  << " ";
    }
}