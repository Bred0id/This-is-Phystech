#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int a = 0;
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a;
        res ^= a;
    }
    std::cout << res << "\n";
}