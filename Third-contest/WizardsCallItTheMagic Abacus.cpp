#include <iostream>
#include <cstdint>

uint64_t MinTwo(uint64_t a, uint64_t b)
{
    return (a < b) ? a : b;
}

uint64_t MinThree(uint64_t a, uint64_t b, uint64_t c)
{
    if (MinTwo(a, b) < MinTwo(a, c))
    {
        return MinTwo(a, b);
    }
    return MinTwo(a, c);
}

uint64_t Answer(uint64_t n)
{
    auto dp = new uint64_t[n + 1]{};
    dp[1] = 0;
    for (uint64_t i = 2; i <= n; i++)
    {
        if (i % 6 == 0)
        {
            dp[i] = MinThree(dp[i - 1], dp[i / 2], dp[i / 3]) + 1;
        }
        else if (i % 3 == 0)
        {
            dp[i] = MinTwo(dp[i - 1], dp[i / 3]) + 1;
        }
        else if (i % 2 == 0)
        {
            dp[i] = MinTwo(dp[i - 1], dp[i / 2]) + 1;
        }
        else
        {
            dp[i] = dp[i - 1] + 1;
        }
    }
    uint64_t ans = dp[n];
    delete[] dp;
    return ans;
}

int main()
{
    uint64_t n = 0;
    std::cin >> n;
    std::cout << Answer(n);
}