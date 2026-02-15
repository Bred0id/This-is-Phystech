#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

const int cOst = 10;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<long double> mass(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> mass[i];
    }
    std::vector<long double> pref(n + 1, 1.0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + std::log(mass[i]);
    }
    int k = 0;
    std::cin >> k;
    std::cout << std::fixed << std::setprecision(cOst);
    for (int j = 0; j < k; j++)
    {
        int l = 0;
        int r = 0;
        std::cin >> l >> r;
        long double ans = pref[r + 1] - pref[l];
        long double mean = std::exp(ans / (r - l + 1));
        std::cout << mean << "\n";
    }
}