#include <iostream>
#include <cstdint>

void Swap(int64_t &a, int64_t &b)
{
    a = a - b;
    b = a + b;
    a = b - a;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n = 0;
    int64_t w = 0;
    int64_t h = 0;
    std::cin >> w >> h >> n;
    if (h > w)
    {
        Swap(w, h);
    }
    int64_t r = w * n;
    int64_t l = w;
    int64_t mid = r;
    while (r - l > 1)
    {
        mid = (r + l) / 2;
        if ((mid / w) * (mid / h) >= n)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    std::cout << r;
}