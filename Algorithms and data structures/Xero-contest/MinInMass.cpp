#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<int> mass(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> mass[i];
    }
    std::vector<int> pref(n);
    pref[0] = mass[0];
    for (int i = 1; i < n; i++)
    {
        if (mass[i] < pref[i - 1])
        {
            pref[i] = mass[i];
        }
        else
        {
            pref[i] = pref[i - 1];
        }
    }
    std::vector<int> suf(n);
    suf[n - 1] = mass[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (mass[i] < suf[i + 1])
        {
            suf[i] = mass[i];
        }
        else
        {
            suf[i] = suf[i + 1];
        }
    }
    int k = 0;
    std::cin >> k;
    for (int j = 0; j < k; j++)
    {
        int l = 0;
        int r = 0;
        std::cin >> l >> r;
        l -= 1;
        r -= 1;
        int ans = 0;
        if (pref[l] < suf[r])
        {
            ans = pref[l];
        }
        else
        {
            ans = suf[r];
        }
        std::cout << ans << "\n";
    }
}