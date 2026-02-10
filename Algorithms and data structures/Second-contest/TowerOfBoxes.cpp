#include <iostream>
#include <cstdint>

uint64_t Max(uint64_t &a, uint64_t &b)
{
    return a > b ? a : b;
}

int main()
{
    uint64_t full_height = 0;
    int n = 0;
    std::cin >> n;
    uint64_t h = 0;
    uint64_t w = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> h >> w;
        full_height += Max(h, w);
    }
    std::cout << full_height;
}